#include <iostream>

#include "ScopedPtr.h"

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF) ;
	ScopedPtr<int> p1{new int{3}} ;
	*p1 = 100 ;
	std::cout << *p1 << '\n' ;

	ScopedPtr<std::string> p2{new std::string{"Using smart pointer"}} ;
	std::cout << *p2 << '\n' ;
	p2->assign("New string") ;
	std::cout << *p2 << '\n' ;

	ScopedPtr<int[]> p3{new int[4]{1,2,3,4}} ;
	//std::cout << *(p3.get() + 1) << '\n' ;
	std::cout << p3[1] << '\n' ;
	p3[1]  = 100 ;
	//std::cout << *(p3.get() + 1) << '\n' ;
	std::cout << p3[1] << '\n' ;
}
