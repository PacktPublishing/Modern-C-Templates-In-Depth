#include <iterator>
#include <string>
#include <unordered_map>
#include <vector>
namespace TypeDef {
	typedef long long llong;
	typedef unsigned long ulong;
	typedef unsigned long long ullong;

	typedef int* INTPTR;
	typedef int& INTREF;

	template<typename T>
	class Container {
	public:
		typedef std::random_access_iterator_tag iterator_category;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef const T* const_pointer;
		typedef const T& const_reference;
	};

	//int (*GetOperation(int index))(int,int) {
	//	
	//}

	typedef int (*OperationFn)(int, int);
	OperationFn GetOperation(int index) {

	}

	typedef std::vector<std::pair<int, std::string>> Data;
}

using llong = long long;
using ulong = unsigned long ;
using ullong = unsigned long long ;

using INTPTR = int* ;
using INTREF = int& ;

template<typename T>
class Container {
public:
	using iterator_category = std::random_access_iterator_tag;
	using value_type = T;
	using pointer = T*;
	using reference = T&;
	using const_pointer = const T*;
	using const_reference = const T&;
};

//int (*GetOperation(int index))(int,int) {
//	
//}

using OperationFn = int (*)(int, int);

OperationFn GetOperation(int index) {

}

//using Data = std::vector<std::pair<int, std::string>>;

template<typename Value>
using Data = std::vector<std::pair<int, Value>> ;

template<typename T>
using TransitionTable = std::unordered_map<T, std::string> ;
int main() {
	long long var{};

	//int (*pfn)(int,int) = GetOperation(0) ;
	OperationFn pfn = GetOperation(0);

	Data<std::string> d{};
	TransitionTable<char> table1 ;
	TransitionTable<int> table2 ;

}