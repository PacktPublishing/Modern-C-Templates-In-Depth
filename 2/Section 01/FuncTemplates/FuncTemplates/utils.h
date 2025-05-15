#pragma once
#include <iostream>
template<typename T>
T Max(T a, T b) {
	return a > b ? a : b ;
}
template<typename T>
constexpr T Square(T a) {
	return a * a ;
}

template<typename TResult, typename T1, typename T2>
TResult Product1(T1 a, T2 b) {
	return a * b ;
}

template<typename T1, typename T2>
auto Product2(T1 a, T2 b) {
	return a * b ;
}

template<typename T1, typename T2>
std::common_type_t<T1, T2> Product3(T1 a, T2 b) {
	return a * b ;
}

template<typename T1, typename T2,
	typename ResultT=std::common_type_t<T1, T2>>
ResultT Product(T1 a, T2 b) {
	return a * b ;
}

void Bar() ;