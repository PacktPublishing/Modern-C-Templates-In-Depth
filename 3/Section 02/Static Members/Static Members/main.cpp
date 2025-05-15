#include "Stack.h"

int main() {
	Stack<int> s{5} ;
	for (int i = 0 ; i < 5 ; ++i) {
		s.Push(i) ;
	}
	s.Print() ;

	Stack<int> s2{8} ;

	Stack<int>::PrintInstances() ;

	Stack<float> s3{5} ;
	Stack<float>::PrintInstances() ;
}
