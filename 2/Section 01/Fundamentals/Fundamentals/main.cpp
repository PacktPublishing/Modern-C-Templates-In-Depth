#include <cstdlib>
#include <iostream>

int Comparator(const void *first, const void *second) {
	auto arg1 = *static_cast<const int*>(first) ;
	auto arg2 = *static_cast<const int*>(second) ;
	if(arg1 < arg2)
		return -1 ;
	if(arg1 > arg2)
		return 1 ;
	return 0 ;
}
void UsingVoidStar() {
	int values[] = {6, 2, 9, 1, 3} ;
	for(auto v : values) {
		std::cout << v << ' ' ;
	}
	qsort(values, 5, sizeof(int), Comparator ) ;

	std::cout << "\n Sorted\n" ;
	for(auto v : values) {
		std::cout << v << ' ' ;
	}
}

#define Max(x, y) (x > y ? x : y)
#define Square(x) x * x //i+5 * i+5

void UsingPreprocessor() {
	int i = 5 ;
	auto result = Square(i+5) ;
	std::cout << Max(1, 2) ;
}

void UsingDiffNames() {
	float num = -5 ;
	std::fabs(num) ;
}

int main() {
	UsingDiffNames() ;
	UsingPreprocessor() ;
	UsingVoidStar() ;
}
