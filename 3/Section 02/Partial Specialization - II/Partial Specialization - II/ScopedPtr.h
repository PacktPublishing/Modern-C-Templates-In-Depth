#pragma once
template<typename T>
class ScopedPtr
{
	T *m_ptr{} ;

public:
	explicit ScopedPtr(T* ptr)
		: m_ptr{ptr} {
	}
	void reset() {
		delete m_ptr ;
	}
	~ScopedPtr() {
		reset() ;
	}
	ScopedPtr(const ScopedPtr &) =delete ;
	ScopedPtr & operator=(const ScopedPtr &) = delete ;

	ScopedPtr(ScopedPtr &&other)noexcept : m_ptr{other.m_ptr} {
		other.m_ptr = nullptr ;
	}
	ScopedPtr & operator=(ScopedPtr &&other)noexcept {
		if (this != &other) {
			reset() ;
			m_ptr = other.m_ptr ;
			other.m_ptr = nullptr ;
		}
		return *this ;
	}
	T *get()const noexcept {
		return m_ptr ;
	}
	T * operator->()const noexcept {
		return m_ptr ;
	}
	T& operator *()const noexcept {
		return *m_ptr ;
	}
};

template<typename T>
class ScopedPtr<T[]>
{
	T *m_ptr{} ;

public:
	explicit ScopedPtr(T* ptr)
		: m_ptr{ptr} {
	}
	void reset() {
		delete[] m_ptr ;
	}
	~ScopedPtr() {
		reset() ;
	}
	ScopedPtr(const ScopedPtr &) =delete ;
	ScopedPtr & operator=(const ScopedPtr &) = delete ;

	ScopedPtr(ScopedPtr &&other)noexcept : m_ptr{other.m_ptr} {
		other.m_ptr = nullptr ;
	}
	ScopedPtr & operator=(ScopedPtr &&other)noexcept {
		if (this != &other) {
			reset() ;
			m_ptr = other.m_ptr ;
			other.m_ptr = nullptr ;
		}
		return *this ;
	}
	T *get()const noexcept {
		return m_ptr ;
	}
	T& operator[](size_t index)noexcept {
		return m_ptr[index] ;
	}
	const T& operator[](size_t index)const noexcept {
		return m_ptr[index] ;
	}
};