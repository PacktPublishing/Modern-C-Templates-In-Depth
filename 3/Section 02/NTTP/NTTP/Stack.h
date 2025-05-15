#pragma once
#include <stdexcept>
#include <iostream>

template<typename T = int, size_t SIZE = 10>
class Stack {
	T m_pBuffer[SIZE];
	size_t m_Top{};
public:
	void Push(const T& element) {
		if (Full()) {
			throw std::logic_error{ "Stack is full" };
		}
		m_pBuffer[m_Top] = element;
		++m_Top;
	}
	void Pop() {
		if (Empty()) {
			throw std::logic_error{ "Stack is empty" };
		}
		--m_Top;
	}
	T& Top() const {
		if (Empty()) {
			throw std::logic_error{ "Stack is empty" };
		}
		return m_pBuffer[m_Top - 1];
	}
	bool Empty() const {
		return m_Top == 0;
	}
	bool Full() const {
		return m_Top == SIZE;
	}
	void Print()const {
		if (Empty()) {
			std::cout << "Stack is empty!\n";
			return;
		}
		for (size_t i = m_Top; i > 0; --i) {
			std::cout << m_pBuffer[i - 1] << ' ';
		}
		std::cout << '\n';
	}
	size_t Size() const {
		return m_Top;
	}
};

