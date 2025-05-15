#include "Stack.h"

int main() {
	Stack<int> s{5} ;
	for (int i = 0 ; i < 5 ; ++i) {
		s.Push(i) ;
	}
	s.Print() ;

	Stack<float> sf{5} ;
}
