#include "Stack.h"

int main() {
	Stack<int,5> s1 ;
	for (int i = 0 ; i < 5 ; ++i) {
		s1.Push(i) ;
	}
	s1.Print() ;

	Stack<> s2 ;
	for (int i = 0 ; i < 5 ; ++i) {
		s2.Push(i * 10) ;
	}
	s2.Print() ;

}
