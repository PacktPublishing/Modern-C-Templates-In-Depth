#pragma once
#include <iostream>
void CallTemplate()  ;

template<typename T>
static void Print(T data) {
	static int counter{} ;
	std::cout << counter++ << ". " << data << '\n' ;
}