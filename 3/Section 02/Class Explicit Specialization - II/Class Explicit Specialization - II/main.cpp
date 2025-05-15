#include "Stack.h"

template<>
struct Printer<Stack<int>> {
	void operator()(const Stack<int>* p, size_t top)const {
		for (size_t i = top; i > 0; --i) {
			p[i - 1].Print();
		}
		std::cout << '\n';
	}
};

struct FunctionInfo {
	std::string m_Name{} ;
	std::string m_Address{} ;
};

//template<>
//struct Printer<FunctionInfo> {
//	void operator()(const FunctionInfo *p, size_t top)const {
//		while (top != 0) {
//			--top ;
//			std::cout << p[top].m_Address << ' ' << p[top].m_Name << '\n' ;
//		}
//	}
//};

struct CallStackInfo {
	void operator()(const FunctionInfo *p, size_t top)const {
		while (top != 0) {
			--top ;
			std::cout << p[top].m_Address << ' ' << p[top].m_Name << '\n' ;
		}
	}
};
int main() {
	/*
	Stack<int> s1{5} ;
	for (int i = 0 ; i < 5 ; ++i) {
		s1.Push(i) ;
	}
	//s1.Print() ;

	Stack<int> s2{5} ;
	for (int i = 0 ; i < 5 ; ++i) {
		s2.Push(i * 10) ;
	}
	//s2.Print() ;

	Stack<Stack<int>> stack_ints{2} ;
	stack_ints.Push(s1) ;
	stack_ints.Push(s2) ;

	stack_ints.Print() ;*/
	Stack<FunctionInfo, CallStackInfo> func_stack{5} ;
	func_stack.Push({"A", "0x1"}) ;
	func_stack.Push({"B", "0x2"}) ;
	func_stack.Push({"C", "0x3"}) ;
	func_stack.Push({"D", "0x4"}) ;
	func_stack.Push({"E", "0x5"}) ;

	func_stack.Print() ;
}
