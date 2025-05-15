#pragma once
#include <iostream>
template<typename ValueT, typename StreamT>
class Writer
{
	ValueT *m_pValue{} ;
	StreamT *m_pStream{} ;

public:
	Writer(ValueT& pValue, StreamT& pStream)
		: m_pValue{&pValue},
		  m_pStream{&pStream} {
	}
	void Serialize() {
		*m_pStream << *m_pValue ;
	}
};

template<typename ValueT>
class Writer<ValueT, std::ostream>
{
	ValueT *m_pValue{} ;

public:
	Writer(ValueT& pValue)
		: m_pValue{&pValue} {
	}
	void Serialize() {
		std::cout << "[ostream] " << *m_pValue ;
	}
};