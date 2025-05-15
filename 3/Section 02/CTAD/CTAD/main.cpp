#include <string>

#include "Pair.h"

int main() {
	using namespace std::string_literals ;
	Pair p1{101, "C++"} ;
	auto p2 = MakePair(101, "C++"s) ;
}
