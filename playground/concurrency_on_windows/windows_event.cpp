/*******************************************************************************
 * @brief		Concurrency: Thread on Windows
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 *		2018.12.30	Created.
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

	explicit WinException(unsigned long value = GetLastError()) : error{ value } {}
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

/* Private Functions ---------------------------------------------------------*/
static void CheckEventSignal(bool b) {
	if (b) {
		std::cout << "  The event is signaled" << std::endl;
	} else {
		std::cout << "  The event is not signaled" << std::endl;
	}
}

/* Main Routine --------------------------------------------------------------*/
auto main() -> int {
	std::cout << "> concurrency: event on windows" << std::endl;

	auto ev = Event{
		EventType::ManualReset
	};
	CheckEventSignal(ev.Wait(0));
	ev.Set();
	CheckEventSignal(ev.Wait(0));
	ev.Clear();
	CheckEventSignal(ev.Wait(0));

	return 0;
}
