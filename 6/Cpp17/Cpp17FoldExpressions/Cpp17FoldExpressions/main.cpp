

#include <iostream>

//template<typename T>
//const T& Sum(const T &t) {
//	return t ;
//}

template<typename T, typename...Args>
T Sum(const T& first, const Args&...args) {
	if constexpr (sizeof...(args)==0) {
		return first ;
	}else {
		return first + Sum(args...) ;
	}
}

template<typename...Args>
auto Sum(Args...args) {
	return (args + ...) ;//(1 + (2 + (3 + 4)))
}

//void Print() {
//}

template<typename...Args>
void Print(const Args& ...args) {
	(std::cout << ... << args) ;
}


int main() {
	auto result = Sum(1,2,3,4) ;
	std::cout << result << '\n' ;

	Print(1, 2.0f, "Three") ;
}