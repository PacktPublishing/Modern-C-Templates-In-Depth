#pragma once
#include <iostream>

void CallTemplate() ;
void UseTemplate() ;

template<typename T>
T Max(T a, T b) {
	return a > b ? a : b ;
}

extern template int Max(int,int) ;