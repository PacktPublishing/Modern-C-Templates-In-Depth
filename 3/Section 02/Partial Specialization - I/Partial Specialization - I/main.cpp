#include "Writer.h"
#include <iostream>
#include <fstream>
#include <sstream>



int main() {
	int value{10} ;
	Writer<int, std::ostream> writer{value} ;
	writer.Serialize() ;

	std::string s = "Using partial specialization" ;
	Writer<std::string, std::ostream> s_writer{s} ;
	s_writer.Serialize() ;

	std::ofstream out{"file.txt"} ;
	Writer file_writer{value, out} ;
	file_writer.Serialize() ;
}
