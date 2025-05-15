#pragma once
template<typename T1, typename T2>
class Pair
{
	T1 m_First{} ;
	T2 m_Second{} ;
public:
	Pair()=default ;
	Pair(T1 first, T2 second):m_First{first}, m_Second{second} {
		
	}
	T1 & GetFirst() {
		return m_First ;
	}
	const T1 & GetFirst()const {
		return m_First ;
	}
	T2 & GetSecond() {
		return m_Second ;
	}
	const T2 & GetSecond()const {
		return m_Second ;
	}
	void SetFirst(T1 first) {
		m_First = first ;
	}
	void SetSecond(T2 second) {
		m_Second = second ;
	}
};

template<typename T1, typename T2>
Pair<T1, T2> MakePair(T1 first, T2 second) {
	return {first, second} ;
}