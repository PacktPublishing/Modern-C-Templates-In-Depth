#include "Stack.h"
void TestStackInt() {
    Stack<int> stack(5);

    // Test pushing elements
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Print(); // Expected output: 3 2 1

    // Test popping elements
    stack.Pop();
    stack.Print(); // Expected output: 2 1

    // Test top element
    std::cout << "Top element: " << stack.Top() << std::endl; // Expected output: 2

    // Test size and empty
    std::cout << "Stack size: " << stack.Size() << std::endl; // Expected output: 5
    std::cout << "Is stack empty? " << (stack.Empty() ? "Yes" : "No") << std::endl; // Expected output: No

    // Test full condition
    stack.Push(4);
    stack.Push(5);
    stack.Push(6);
    std::cout << "Is stack full? " << (stack.Full() ? "Yes" : "No") << std::endl; // Expected output: Yes

    // Test exception handling for full stack
    try {
        stack.Push(7);
    } catch (const std::logic_error& e) {
        std::cout << "Exception: " << e.what() << std::endl; // Expected output: Stack is full
    }

    // Test exception handling for empty stack
    while (!stack.Empty()) {
        stack.Pop();
    }
    try {
        stack.Pop();
    } catch (const std::logic_error& e) {
        std::cout << "Exception: " << e.what() << std::endl; // Expected output: Stack is empty
    }
}

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF) ;
	Stack<int> s{5} ;
	for (int i = 0 ; i < 5 ; ++i) {
		s.Push(i) ;
	}

	//s.Print() ;

	while (!s.Empty()) {
		std::cout << s.Top() << ' ' ;
		s.Pop() ;
	}

	Stack<std::string> numbers{5} ;
	numbers.Push("One") ;
	numbers.Push("Two") ;
	numbers.Push("Three") ;
	numbers.Push("Four") ;
	numbers.Push("Five") ;

	numbers.Print() ;

	Stack<std::string> numbers2{5} ;
	numbers2.Push("One") ;
	numbers2.Push("Two") ;
	numbers2.Push("Three") ;
	numbers2.Push("Four") ;
	numbers2.Push("Five") ;

	Stack<Stack<std::string>> strings_stack{2} ;
	strings_stack.Push(numbers) ;
	strings_stack.Push(numbers2) ;

	//strings_stack.Print() ;
	while (!strings_stack.Empty()) {
		auto &s = strings_stack.Top() ;
		while (!s.Empty()) {
			std::cout << s.Top() << ' ' ;
			s.Pop() ;
		}
		std::cout << '\n' ;
		strings_stack.Pop() ;
	}
}
