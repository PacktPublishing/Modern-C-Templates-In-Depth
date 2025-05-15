#pragma once
#include <iostream>

template<typename T>
class ListPrinter {
public:
	void PrePrint()const {
		
	}
	void Print(const T &element)const {
		std::cout << element << ' ' ;
	}
	void PostPrint()const {
		
	}
};

template<typename T, typename Printer = ListPrinter<T>>
class List {
	struct Node {
		T m_Data{} ;
		Node *m_pNext{} ;
		Node *m_pPrevious{} ;
		template<typename...Args>
		Node(Args&&...data)
			: m_Data{std::forward<Args>(data)...}{
		}
	};
	Node *m_pHead{} ;
	Node *m_pTail{} ;
	std::size_t m_Size{} ;
public:
#pragma region Traversal
	class Position {
		Node *m_pCurrent{} ;
		Position() = default ;
		Position(Node* pCurrent)
			: m_pCurrent{pCurrent} {
		}
		friend class List ;
	};
	Position First()const {
		return Position{m_pHead} ;
	}
	const T& GetAt(const Position &at)const {
		return at.m_pCurrent->m_Data ;
	}
	T& GetAt(const Position &at){
		return at.m_pCurrent->m_Data ;
	}
	void Next(Position &at)const {
		at.m_pCurrent = at.m_pCurrent->m_pNext ;
	}
	bool End(Position at)const {
		return at.m_pCurrent == nullptr ;
	}
#pragma endregion

	List()=default ;
	List(std::initializer_list<T> list) {
		for (auto &element : list) {
			Add(std::move(element)) ;
		}
	}
	void Add(T&& element) {
		Emplace(std::move(element)) ;
	}
	void Add(const T& element) {
		Emplace(element) ;
	}
	template<typename...Args>
	void Emplace(Args&&...args) {
		auto new_node = new Node{std::forward<Args>(args)...} ;
		if (Empty()) {
			m_pHead = m_pTail = new_node ;
		}else {
			m_pTail->m_pNext = new_node ;
			new_node->m_pPrevious = m_pTail ;
			m_pTail = new_node ;
		}
		++m_Size ;
	}
	~List() {
		auto to_delete = m_pHead ;
		while (m_pHead) {
			m_pHead = m_pHead->m_pNext ;
			delete to_delete ;
			to_delete = m_pHead ;
		}
	}
	void Print() {
		Printer printer{} ;
		printer.PrePrint() ;
		for (auto node = m_pHead ; node != nullptr ; node = node->m_pNext) {
			printer.Print(node->m_Data);
		}
		printer.PostPrint() ;
	}
	bool Empty()const {
		return m_Size == 0 ;
	}
	std::size_t Size()const {
		return m_Size ;
	}

	template<typename...Args>
	void Insert(Position at, Args&&...args) {
		if (Empty()) {
			return ;
		}
		if (at.m_pCurrent == m_pHead) {
			/*
			 *1. Create a new node
			 *2. New node's next should point to head
			 *3. Head's previous should point to new node
			 *4. Make new node the head of the list
			 */
			auto new_node = new Node{std::forward<Args>(args)...} ;
			new_node->m_pNext = m_pHead ;
			m_pHead->m_pPrevious = new_node ;
			m_pHead = new_node ;
		}else {
			/*
			 *1. Create a new node
			 *2. Point its next to current node
			 *3. Assign current node's previous to new node's previous
			 *4. Update previous node's next pointer with the new node
			 */

			auto prev_node = at.m_pCurrent->m_pPrevious ;
			auto new_node = new Node{std::forward<Args>(args)...} ; 
			new_node->m_pNext = at.m_pCurrent ;
			new_node->m_pPrevious = prev_node ;
			prev_node->m_pNext = new_node ;
		}
		++m_Size ;  
	}
	void Erase(Position at) {
		if (Empty()) {
			return ;
		}
		auto node_to_delete = at.m_pCurrent ;
		if (at.m_pCurrent == m_pHead) {
			/*
			 *1. Move head to next
			 *2. Assign null to head's previous to break the link
			 *3. Delete the old head
			 */
			m_pHead = m_pHead->m_pNext ;
			m_pHead->m_pPrevious = nullptr ;
		}else if (at.m_pCurrent == m_pTail) {
			/*
			 *1. Make tail's previous as the tail
			 *2. Assign null to new tail's next to break the link
			 *3. Delete the old tail
			 */
			m_pTail = m_pTail->m_pPrevious ;
			m_pTail->m_pNext = nullptr ;
		}else {
			/*
			 *1. Get the next of the current node (N)
			 *2. Get the previous of the current node (P)
			 *3. Assign N to P->next
			 *4. Assign P to N->prev
			 */
			auto next_node = at.m_pCurrent->m_pNext ;
			auto prev_node = at.m_pCurrent->m_pPrevious ;
			prev_node->m_pNext = next_node ;
			next_node->m_pPrevious = prev_node ;
		}
		delete node_to_delete ;
		--m_Size ;
	}
};