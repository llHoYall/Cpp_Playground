/*******************************************************************************
 * @brief		Lazy evaluation in modern C++
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.12.27	Created.
 ******************************************************************************/

#ifndef __LAZY_EVALUATION_H__
#define __LAZY_EVALUATION_H__

/* Include Headers -----------------------------------------------------------*/
#include <functional>
#include <memory>

/* Class Declarations --------------------------------------------------------*/
template<class T> class Row;

template<class T> class Delay {
public:
	Delay(std::function<T()> fn) : m_fn(fn) {}

	T Fetch(void) {
		return m_fn();
	}

private:
	std::function<T()> m_fn;
};

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

template<class T> class Chunk {
public:
	Chunk(void) {}
	Chunk(T value, Row<T> last_row) : m_value(value), m_last_row(std::move(last_row)) {}
	explicit Chunk(T value) : m_value(value) {}

	T GetValue(void) const {
		return m_value;
	}

	Row<T> ShiftLastToFirst(void) const {
		return m_last_row;
	}

private:
	T m_value;
	Row<T> m_last_row;
};

template<class T> class ChunkPreparation {
public:
	T m_value;
	Row<T> m_row;

	ChunkPreparation(T value, Row<T> row) : m_value(value), m_row(std::move(row)) {}
	explicit ChunkPreparation(T value) : m_value(value) {}

	Chunk<T> operator()() {
		return Chunk<T>(m_value, m_row);
	}
};

template<class T> class Row {
public:
	Row(void) {}
	explicit Row(T value) {
		auto chunk = ChunkPreparation<T>(value);
		m_lazy_chunk = std::make_shared<Memoization<Chunk<T>>>(chunk);
	}
	Row(T value, Row row) {
		auto chunk = ChunkPreparation<T>(value, std::move(row));
		m_lazy_chunk = std::make_shared<Memoization<Chunk<T>>>(chunk);
	}
	Row(std::function<Chunk<T>()> fn) : m_lazy_chunk(std::make_shared<Memoization<Chunk<T>>>(fn)) {}

	bool IsEmpty(void) const {
		return !m_lazy_chunk;
	}

	T Fetch(void) const {
		return m_lazy_chunk->Fetch().GetValue();
	}

	Row<T> ShiftLastToFirst(void) const {
		return m_lazy_chunk->Fetch().ShiftLastToFirst();
	}

	Row Pick(int n) const {
		if (n == 0 || IsEmpty()) {
			return Row();
		}

		auto chunk = m_lazy_chunk;
		return Row([chunk, n]() {
			auto val = chunk->Fetch().GetValue();
			auto row = chunk->Fetch().ShiftLastToFirst();
			return Chunk<T>(val, row.Pick(n - 1));
		});
	}

private:
	std::shared_ptr <Memoization<Chunk<T>>> m_lazy_chunk;
};

template<class T> Row<T> ConcatenateRows(Row<T> left_row, Row<T> right_row) {
	if (left_row.IsEmpty()) {
		return right_row;
	}
	return Row<T>([=]() {
		return Chunk<T>(left_row.Fetch(), ConcatenateRows<T>(left_row.ShiftLastToFirst(), right_row));
	});
}

template<class T, class U> void ForEach(Row<T> row, U fn) {
	while (!row.IsEmpty()) {
		fn(row.Fetch());
		row = row.ShiftLastToFirst();
	}
}

#endif
