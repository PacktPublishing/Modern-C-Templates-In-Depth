#include <type_traits>
#include <iostream>
#include <deque>
#include <string>
template<typename T1, typename T2>
std::common_type_t<T1, T2> Max(T1 x, T2 y) {
	return x > y ? x : y ;
}
template<typename T>
class Stack {
	std::deque<T> storage ;
public:
	Stack(const T &elem) {
		Push(elem) ;
	}
	void Push(const T &elem) {
		storage.push_back(elem) ;
	}
	void Pop() {
		assert(storage.empty()) ;
		storage.pop_back() ;
	}
	const T & Top()const {
		return storage.back() ;
	}
	template<typename U>
	friend std::ostream & operator <<(std::ostream &out, const Stack<U> &s) ;
};
template<typename U>
std::ostream & operator <<(std::ostream &out, const Stack<U> &s) {
	for(auto x : s.storage) {
		out << x << ' ' ;
	}
	return out ;
}
Stack(const char *)->Stack<std::string> ;
int main() {
	auto val = Max(3,8.5) ;
	std::cout << val << std::endl;
	Stack s{"hello"};
	s.Push("5") ;
	s.Push("3") ;
	s.Push("1") ;
	std::cout << s ;
}
