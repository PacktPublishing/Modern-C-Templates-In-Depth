#include "utils.h"
template int Max(int,int) ;

void CallTemplate() {
	//Max(1,2) ;
}

template<typename T>
T Max(T a, T b) {
	return a > b ? a : b ;
}
//template float Divide(float, float) ;
template double Divide(double, double) ;
template long double Divide(long double, long double) ;

template<typename T>
T Divide(T a, T b) {
	return a / b ;
}