#include <iostream>

#include "utils.h"

void Basics() {
	auto result1 = Max<double>(3,5.6) ;
	auto result2 = Max(1.3,8.5) ;

	std::cout << result1 << '\n' ;
	std::cout << result2 << '\n' ;

	int num = 5 ;
	auto squared = Square(num+1) ;
	std::cout << "Squared value is :" << squared << '\n' ;

	std::cout << "Product:" << Product(5, 2.5) ;
}


#pragma region Type Conversions
template<typename T>
void Foo(T a) {
	std::cout << typeid(T).name() << '\n';
}

void A() {

}
void B() {

}
void Conversions() {
	Foo(3u);
	Foo(8);
	Foo('a');

	const int x = 5;
	Foo(x);

	int y = 10;
	Foo(&y);

	int arr[5];
	Foo(arr);

	Foo(A);
	Foo(B);

	std::cout << Square<int> << '\n';
	Square(8);
	Bar();
}
#pragma endregion

#pragma region Nontype Template Parameters
template<auto value>
void Print() {
	std::cout << value << '\n' ;
}

template<typename T>
size_t Find1(const T *pArr, size_t size, const T & value) {
	for(size_t i = 0 ; i < size ; ++i) {
		if(pArr[i] == value) {
			return i ;
		}
	}
	return std::numeric_limits<size_t>::max() ;
}

template<typename T, size_t size>
size_t Find(const T( &pArr)[size],const T & value) {
	for(size_t i = 0 ; i < size ; ++i) {
		if(pArr[i] == value) {
			return i ;
		}
	}
	return std::numeric_limits<size_t>::max() ;
}

#pragma endregion

int main() {
	int i = 5 ;
	auto p = &i ;
	Print<'a'>() ;

	int arr[] = {1,2,3,4,5} ;
	auto pos = Find(arr, 3) ;
	if(pos != std::numeric_limits<size_t>::max()) {
		std::cout << "Found at:" << pos << '\n' ;
	}
}
