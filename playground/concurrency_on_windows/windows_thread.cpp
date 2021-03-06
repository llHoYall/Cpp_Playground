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
	UniqueHandle(UniqueHandle&& other) : m_value { other.Release() } {}

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

/* Private Functions ---------------------------------------------------------*/
static auto WINAPI ThreadProc(LPVOID) -> DWORD {
	std::cout << "  ThreadProc" << std::endl;
	return 100;
}

static auto WaitOneThread(const HANDLE h, const DWORD ms = INFINITE) -> bool {
	const auto r = WaitForSingleObject(h, ms);
	if (r == WAIT_OBJECT_0) {
		return true;
	}
	if (r == WAIT_TIMEOUT) {
		return false;
	}
	throw WinException();
}

/* Main Routine --------------------------------------------------------------*/
auto main() -> int {
	std::cout << "> concurrency: thread on windows" << std::endl;

	auto hnd = NullHandle {
		CreateThread(nullptr, 0, ThreadProc, nullptr, 0, nullptr)
	};

	if (hnd) {
		if (WaitOneThread(hnd.Get(), 0)) {
			std::cout << "  Before running thread" << std::endl;
		}
		WaitOneThread(hnd.Get());
		if (WaitOneThread(hnd.Get(), 0)) {
			std::cout << "  After running thread" << std::endl;
		}
		unsigned long exitCode;
		GetExitCodeThread(hnd.Get(), &exitCode);
		std::cout << "  The result = " << exitCode << std::endl;
	}
	
	return 0;
}
