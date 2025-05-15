#include <type_traits>
template<typename T>
constexpr T size = 100 ;

template<typename T>
constexpr T pi = T{3.14159265} ;


template<typename T>
T Area(T radius) {
	return pi<T> * radius * radius ;
}

template<typename T>
bool IsPointerV = std::is_pointer<T>::value ;

int main() {
	auto a = size<int> ;
	auto a1 = Area(1.23f) ;
	auto a2 = Area(1.23) ;
	auto a3 = Area(1.23L) ;

	//constexpr auto result = std::is_pointer<int*>::value  ;
	constexpr auto result = IsPointerV<int*> ;


	auto sqr = [](auto a) {
		return a * a ;
	} ;
	sqr(2) ;
	sqr(3.13) ;

}