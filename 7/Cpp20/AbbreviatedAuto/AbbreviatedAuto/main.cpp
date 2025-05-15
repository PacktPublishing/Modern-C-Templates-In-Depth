#include <iostream>
#include <concepts>
//template<typename T> requires std::integral<T>
//T Max(T a, T b) {
//	return a > b ? a : b ;
//}


auto Max(std::integral auto a,std::integral auto b) {
	return a > b ? a : b ;
}

//auto Max(auto a, auto b) {
//	return a > b ? a : b ;
//}

int main() {
	auto r = Max(3l,5l) ;
	std::cout <<r << '\n' ;
}