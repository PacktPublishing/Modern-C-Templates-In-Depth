#pragma once
#include <stdexcept>
#include <iostream>
template<typename T>
class Stack {
	T* m_pBuffer{};
	size_t m_Top{};
	size_t m_Size{};
	inline static size_t counter{} ;
public:
	Stack() = default;
#pragma region Rule of 5
	Stack(size_t size) :m_pBuffer{ new T[size] }, m_Size{ size } {
		++counter ;
	}
	Stack(const Stack& other) :
		m_pBuffer{ new T[other.m_Size] },
		m_Top{ other.m_Top },
		m_Size{ other.m_Size } {
		std::copy(other.m_pBuffer, other.m_pBuffer + other.m_Top, m_pBuffer);
	}
	Stack<T>& operator=(const Stack& other) {
		if (this == &other) return *this;

		delete[] m_pBuffer;

		m_Size = other.m_Size;
		m_Top = other.m_Top;
		m_pBuffer = new T[m_Size];
		std::copy(other.m_pBuffer, other.m_pBuffer + other.m_Top, m_pBuffer);

		return *this;
	}
	Stack(Stack&& other) noexcept :
		m_pBuffer{ other.m_pBuffer },
		m_Top{ other.m_Top },
		m_Size{ other.m_Size } {
		other.m_pBuffer = nullptr;
		other.m_Top = 0;
		other.m_Size = 0;
	}
	Stack<T>& operator=(Stack&& other) noexcept {
		if (this == &other) return *this;

		delete[] m_pBuffer;

		m_pBuffer = other.m_pBuffer;
		m_Top = other.m_Top;
		m_Size = other.m_Size;

		other.m_pBuffer = nullptr;
		other.m_Top = 0;
		other.m_Size = 0;

		return *this;
	}
	~Stack() {
		delete[]m_pBuffer;
	}
#pragma endregion

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
		return m_Top == m_Size;
	}
	void Print() {
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

	static void PrintInstances() {
		std::cout << "Total instances for :" << typeid(Stack<T>).name() << " are :" << counter << '\n' ;
	}
};

//template<typename T>
//size_t Stack<T>::counter = 0 ;


