#include <iostream>
template<typename...Rest>
class Printer ;

template<>
class Printer<> {
public:
	void Print()const {
		
	}
};

template<typename T, typename...Rest>
class Printer<T, Rest...> {
	T m_Value{} ;
	Printer<Rest...> m_Rest{} ;//Printer<> m_Rest ;
public:
	Printer(const T& value, const Rest&...rest):m_Value{value}, m_Rest{rest...} {
		
	}
	void Print()const {
		std::cout<< m_Value << ' ' ;
		m_Rest.Print() ;
	}
};

int main() {
	Printer<int,int, float> p{1,2, 3.0f} ;
	p.Print() ;
}