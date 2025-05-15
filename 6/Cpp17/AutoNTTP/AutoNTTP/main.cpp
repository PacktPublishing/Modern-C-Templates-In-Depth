#include <iostream>
//template<int val>
//auto Square() {
//	return val * val ;
//}

template<auto val>
auto Square() {
	return val * val ;
}

template<auto data>
class Printer {
public:
	void Print() {
		std::cout << data << '\n' ;
	}
};

int main() {
	auto result = Square<3l>() ;
	Printer<1> p1{} ;
	Printer<100000L> p2{} ;
	p1.Print() ;
	p2.Print() ;
}