#include <iostream>
#include "utils.h"

//4. Explicit instantiation
template short Max(short, short) ;

int main() {
	//1. Invoking the function
	Max(3,5) ;

	//2. Explicit specialization (defined in utils.cpp)

	//3. Function pointer
	double (*pfn)(double, double) = Max ;
	auto pfn2 = Max<char> ;


}
