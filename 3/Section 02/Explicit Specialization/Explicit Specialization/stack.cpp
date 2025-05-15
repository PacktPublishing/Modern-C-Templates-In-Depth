#include "stack.h"

template<>
void Stack<Stack<int>>::Print() {
	if (Empty()) {
		std::cout << "Stack is empty!\n";
		return;
	}
	for (size_t i = m_Top; i > 0; --i) {
		m_pBuffer[i - 1].Print() ;
	}
	std::cout << '\n';
}