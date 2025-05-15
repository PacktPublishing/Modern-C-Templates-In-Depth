#include <iostream>

template<typename T>
const T& Sum(const T &t) {
	return t ;
}

template<typename T, typename...Args>
T Sum(const T& first, const Args&...args) {
	std::cout << sizeof...(Args) << ' ' << sizeof...(args) << '\n' ;
	return first + Sum(args...) ;
}

//Sum(1,2,3,4) ;

// return 1 + Sum(2,3,4)
// return 2 + Sum(3,4)
// return 3 + Sum(4)

//template<typename T>
//void Print(T arg) {
//	std::cout << arg ;
//}

void Print() {
}

template<typename T, typename...Args>
void Print(const T& first, const Args& ...args) {
	std::cout << first  ;
	if (sizeof...(args) > 0) {
		std::cout << ',' ;
	}
	Print(args...) ;
}

int main() {
	auto result = Sum(1,2,3,4) ;
	std::cout << result << '\n' ;

	Print(1, 2.0f, "Three") ;
}