
#include <iostream>
#include <vector>

struct Noisy {
	Noisy() {
		std::cout << "-- Noisy() --" << '\n' ;
	}
	Noisy(int) {
		std::cout << "-- Noisy(int) --" << '\n' ;
	}
	Noisy(const char *, int){
		std::cout << "-- Noisy(const char *, int) --" << '\n' ;
	}
	~Noisy() {
		std::cout << "-- ~Noisy() --" << '\n' ;
	}
	Noisy(const Noisy&) {
		std::cout << "-- Noisy(const Noisy&) --" << '\n' ;
	}
	Noisy(Noisy&&) {
		std::cout << "-- Noisy(Noisy&&) --" << '\n' ;
	}
	Noisy& operator=(const Noisy&) {
		std::cout << "-- operator=(const Noisy&) --" << '\n' ;
		return *this ;
	}
	Noisy& operator=(Noisy&&) {
		std::cout << "-- operator=(Noisy&&) --" << '\n' ;
		return *this ;
	}
	friend std::ostream& operator<<(std::ostream& os, const Noisy& obj) {
		return os << "N" ;
	}
};
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

template<typename T, typename... Arg>
ScopedPtr<T> MakeScopedPtr(Arg &&...arg) {				//arg...
	return ScopedPtr<T>{new T{std::forward<Arg>(arg)...}} ;//new Noisy{forward(a), forward(b), forward(c)}
}

int main() {
	//auto p = MakeScopedPtr<Noisy>("Hello", 100) ;
	//auto p = std::make_unique<Noisy>("Hello", 100) ;

	std::vector<Noisy> n{} ;
	//Noisy n1{10} ;
	//n.push_back(10) ;
	n.emplace_back("Hello", 100) ;
}