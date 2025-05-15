#include "PrettyPrinter.h"

int main() {
	int data = 100 ;
	PrettyPrinter<int> p{data} ;
	p.Print() ;

	int arr[]{1,2,3,4} ;
	PrettyPrinter<int[]> p_arr{arr, 4} ;
	p_arr.Print() ;
}
