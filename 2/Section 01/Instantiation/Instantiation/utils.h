#pragma once
#include <iostream>

void CallTemplate() ;

template<typename T>
T Max(T a, T b) {
	return a > b ? a : b ;
}

template<>
float Max(float a, float b) ;

template short Max(short, short) ;