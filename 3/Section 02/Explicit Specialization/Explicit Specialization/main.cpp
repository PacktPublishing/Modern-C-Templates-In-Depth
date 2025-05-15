#include "Stack.h"

int main() {
	Stack<int> s1{5} ;
	for (int i = 0 ; i < 5 ; ++i) {
		s1.Push(i) ;
	}
	s1.Print() ;

	Stack<int> s2{5} ;
	for (int i = 0 ; i < 5 ; ++i) {
		s2.Push(i * 10) ;
	}
	s2.Print() ;

	Stack<Stack<int>> stack_ints{2} ;
	stack_ints.Push(s1) ;
	stack_ints.Push(s2) ;

	stack_ints.Print() ;
}
