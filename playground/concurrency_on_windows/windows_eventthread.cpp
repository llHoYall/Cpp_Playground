/*******************************************************************************
 * @brief		Concurrency: Thread with event on Windows
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 *		2018.12.31	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <iostream>
#include <windows.h>

/* Enumerations --------------------------------------------------------------*/
enum class EventType {
	AutoReset,
	ManualReset
};

/* UniqueHandle Class --------------------------------------------------------*/
template<typename C>
class UniqueHandle {
private:
	HANDLE m_value;

	void Close() {
		if (*this) {
			C::Exit(m_value);
		}
	}

public:
	// 복사 대입 Constructor
	UniqueHandle(UniqueHandle const&) = delete;
	auto operator=(UniqueHandle const&)->UniqueHandle& = delete;

	// Move Constructor
	UniqueHandle(UniqueHandle&& other) : m_value{ other.Release() } {}

	// Constructor
	explicit UniqueHandle(HANDLE value = C::Invalid()) : m_value{ value } {}

	// 이동 대입 operator
	auto operator=(UniqueHandle&& other) -> UniqueHandle& {
		if (this != &other) {
			Reset(other.Release());
		}
		return *this;
	}

	~UniqueHandle() {
		Close();
	}

	explicit operator bool() const {
		return m_value != C::Invalid();
	}

	HANDLE Get() const {
		return m_value;
	}

	HANDLE Release() {
		auto value = m_value;
		m_value = C::Invalid();
		return value;
	}

	bool Reset(HANDLE value = C::Invalid()) {
		if (m_value != value) {
			Close();
			m_value = value;
		}
		return static_cast<bool>(*this);
	}
};

/* Structures ----------------------------------------------------------------*/
struct NullHandleCharacteristics {
	static HANDLE Invalid() {
		return nullptr;
	}

	static void Exit(HANDLE value) {
		CloseHandle(value);
	}
};

struct WinException {
	unsigned long error;

	explicit WinException(unsigned long value = GetLastError()) : error { value } {}
};

/* Private Variables ---------------------------------------------------------*/
using NullHandle = UniqueHandle<NullHandleCharacteristics>;

/* Event Class ---------------------------------------------------------------*/
class Event {
public:
	Event(Event const&) = delete;
	Event(Event&& other) throw() : hnd{ other.hnd.Release() } {}
	auto operator=(Event const&)->Event& = delete;
	auto operator=(Event&& other) throw() -> Event& {
		hnd = std::move(other.hnd);
	}
	~Event() = default;

	explicit Event(bool manual) : hnd{ CreateEvent(nullptr, manual, false, nullptr) } {
		if (!hnd) {
			throw WinException();
		}
	}

	explicit Event(EventType type) : hnd{ CreateEvent(nullptr, static_cast<BOOL>(type), false, nullptr) } {
		if (!hnd) {
			throw WinException();
		}
	}

	void Set() {
		std::cout << "  The event is set" << std::endl;
		SetEvent(hnd.Get());
	}

	void Clear() {
		std::cout << "  The event is cleared" << std::endl;
		ResetEvent(hnd.Get());
	}

	auto Wait(const DWORD ms = INFINITE) -> bool {
		const auto result = WaitForSingleObject(hnd.Get(), ms);
		return result == WAIT_OBJECT_0;
	}

private:
	NullHandle hnd;
};

/* Private Variables ---------------------------------------------------------*/
static auto ev = Event{
	// EventType::ManualReset
	EventType::AutoReset
};

/* Private Functions ---------------------------------------------------------*/
static void Wrap(HANDLE*) {}

template<typename T, typename... Args>
static void Wrap(HANDLE* left, const T& right, const Args& ... args) {
	*left = right.Get();
	Wrap(++left, args...);
}

template<typename... Args>
static void WaitAllThreads(const Args& ... args) {
	HANDLE handles[sizeof...(Args)];
	Wrap(handles, args...);
	WaitForMultipleObjects(sizeof...(Args), handles, true, INFINITE);
}

/* No Event
static auto WINAPI ThreadProc(LPVOID) -> DWORD {
	std::cout << "  Thread ID: " << GetCurrentThreadId() << std::endl;	
	return 120;
}
*/

/* With Manual Event 
static auto WINAPI ThreadProc(LPVOID) -> DWORD {
	std::cout << "  Thread ID: " << GetCurrentThreadId() << std::endl;
	ev.Wait();
	std::cout << "  Run Thread ID: " << GetCurrentThreadId() << std::endl;
	return 120;
}
*/

/* With Auto Event */
static auto WINAPI ThreadProc(LPVOID) -> DWORD {
	std::cout << "  Thread ID: " << GetCurrentThreadId() << std::endl;
	ev.Wait();
	std::cout << "  Run Thread ID: " << GetCurrentThreadId() << std::endl;
	Sleep(1000);
	ev.Set();
	return 120;
}

/* Main Routine --------------------------------------------------------------*/
auto main() -> int {
	std::cout << "> concurrency: thread with event on windows" << std::endl;

	/* No Event
	auto thread1 = NullHandle {
		CreateThread(nullptr, 0, ThreadProc, nullptr, CREATE_SUSPENDED, nullptr)
	};
	auto thread2 = NullHandle{
		CreateThread(nullptr, 0, ThreadProc, nullptr, CREATE_SUSPENDED, nullptr)
	};
	ResumeThread(thread1.Get());
	ResumeThread(thread2.Get());
	*/

	/* With Manual & Auto Event */
	auto thread1 = NullHandle{
		CreateThread(nullptr, 0, ThreadProc, nullptr, 0, nullptr)
	};
	auto thread2 = NullHandle{
		CreateThread(nullptr, 0, ThreadProc, nullptr, 0, nullptr)
	};
	Sleep(100);
	ev.Set();
	Sleep(100);

	WaitAllThreads(thread1, thread2);

	return 0;
}
