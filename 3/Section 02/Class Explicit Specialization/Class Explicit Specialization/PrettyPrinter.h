#pragma once
#include <iostream>
template<typename T>
class PrettyPrinter
{
	T* m_Data{} ;
public:
	PrettyPrinter(T &ref):m_Data{&ref} {
		
	}
	void Print()const {
		std::cout << "=======================\n" ;
		std::cout << *m_Data << '\n' ;
	}
};

template<>
class PrettyPrinter<int[]>
{
	int* m_Data{} ;
	size_t m_Size ;
public:
	PrettyPrinter(int *p, size_t size):m_Data{p}, m_Size{size} {
		
	}
	void Print()const {
		std::cout << "=======================\n" ;
		for (size_t i = 0 ; i < m_Size ; ++i) {
			std::cout << m_Data[i] << ' ' ;
		}
		std::cout << '\n' ;
	}
	size_t Size()const {
		return m_Size ;
	}
};