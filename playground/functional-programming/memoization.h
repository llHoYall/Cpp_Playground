/*******************************************************************************
 * @brief		memoization module
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.12.30	Created.
 ******************************************************************************/

#ifndef __MEMOIZATION_H__
#define __MEMOIZATION_H__

/* Class Declarations --------------------------------------------------------*/
template<class T> class Memoization {
public:
	Memoization(std::function<T()> fn) : m_fn(fn), m_subroutine(&ForceSubroutine), m_recordedFunc(T()) {}

	T Fetch(void) {
		return m_subroutine(this);
	}

private:
	T const& (*m_subroutine)(Memoization*);
	mutable T m_recordedFunc;
	std::function<T()> m_fn;

	static T const& ForceSubroutine(Memoization* d) {
		return d->DoRecording();
	}

	static T const& FetchSubroutine(Memoization* d) {
		return d->FetchRecording();
	}

	T const& FetchRecording(void) {
		return m_recordedFunc;
	}

	T const& DoRecording(void) {
		m_recordedFunc = m_fn();
		m_subroutine = &FetchSubroutine;
		return FetchRecording();
	}
};

#endif
