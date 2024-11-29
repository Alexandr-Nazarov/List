#include "MyList.h"


List::List(const Shape& shape) : m_size(1) {
	Head.pNext = &Tail;
	Tail.pPrev = &Head;
	new Node(&Head, &shape);
}


List::List(const List& other) : m_size(other.m_size) {
	//подготовка к копированию
	Head.pNext = &Tail;
	Tail.pPrev = &Head;
	//копирование
	Node* pThis = &Head;
	Node* pOther = other.Head.pNext;
	for (size_t i = 0; i < m_size; i++)
	{
		pThis = new Node(pThis, pOther->m_Data);		
		pOther = pOther->pNext;
	}
}

List::List(List&& other) :m_size(other.m_size) {
	if (other.Head.pNext->pNext) {					  
		Head.pNext = other.Head.pNext;
		Tail.pPrev = other.Tail.pPrev;
		Head.pNext->pPrev = &Head;
		Tail.pPrev->pNext = &Tail;

		other.Head.pNext = &other.Tail;
		other.Tail.pPrev = &other.Head;
		other.m_size = 0;
	}
	else {
		m_size = 0;
		Head.pNext = &Tail;
		Tail.pPrev = &Head;
	}
}

List::~List() {
	while (Head.pNext != &Tail) {
		delete Head.pNext;
	}
}

void List::AddToHead(const Shape& c) {  
	new Node(&Head, &c);				
	m_size++;
}

void List::AddToTail(const Shape& c) {
	
	new Node(Tail.pPrev, &c);
	m_size++;


}

bool List::RemoveOne(const Shape& c) {
	Node* p = Head.pNext;
	while (p != &Tail)
	{
		if (*(p->m_Data) == c)		
		{
			m_size--;
			delete p;
			return true;
		}
		p = p->pNext;
	}
	return false;
}

int List::RemoveAll(const Shape& c) {
	Node* p = Head.pNext;
	int num_del{ 0 };

	while (p != &Tail)
	{
		bool i{ false };
		if (*(p->m_Data) == c)
		{
			m_size--;
			num_del++;
			i = true;
			Node* tmp = p->pNext;
			delete p;
			p = tmp;
		}
		if (i == false) {
			p = p->pNext;
		}
	}
	return num_del;
}

void List::ClearAll() {
	while (this->Head.pNext != &Tail)
	{
		{
			m_size--;
	
			delete this->Head.pNext;
		
		}

	}
}

void List::Sort(SortType sort_type ) {
	if (m_size > 0) {
		Node* p = Head.pNext;
		Node* tmp = new Node;
		for (int i = 0; i < m_size - 1; i++) {
			for (int j = 0; j < m_size - 1 - i; j++) {
				bool sravnenie_bigger = false;
				switch (sort_type)
				{
				case AREA:
					sravnenie_bigger = (this->Head.pNext->m_Data->Area() > this->Head.pNext->pNext->m_Data->Area() ? 1 : 0);
					break;
				case COL:
					sravnenie_bigger = (this->Head.pNext->m_Data->m_color > this->Head.pNext->pNext->m_Data->m_color ? 1 : 0);
					break;
				default:
					break;
				}
				
				if (sravnenie_bigger) {
					tmp->m_Data = this->Head.pNext->pNext->m_Data;
					this->Head.pNext->pNext->m_Data = this->Head.pNext->m_Data;
					this->Head.pNext->m_Data = tmp->m_Data;
				}
				Head.pNext = Head.pNext->pNext;
			}
			Head.pNext = p;
		}
	}
}



std::ostream& operator<<(std::ostream& out, const List& other) {
	Node* pOther = other.Head.pNext;
	for (size_t i = 0; i < other.m_size; i++)
	{		
	
		out << *(pOther->m_Data) << '\n';
		pOther = pOther->pNext;
	}
	return out << '\n';
}

std::ofstream& operator<<(std::ofstream& out, const List& other) {
	Node* pOther = other.Head.pNext;
	for (size_t i = 0; i < other.m_size; i++)
	{
		
		out << *(pOther->m_Data) << '\n';
		pOther = pOther->pNext;
	}
	return out ;
}


std::ifstream& operator>>(std::ifstream& out, List& other) {
	Node* pOther = other.Head.pNext;
	List tmp;
	while (out)
	{
		char type_figure;
		out >> type_figure;
		switch (type_figure)
		{
		case 'c':
			
			pOther->m_Data = new Circle();

			break;
		case 'r':
			
			pOther->m_Data = new Rect();
			break;

		default:
			break;
		}
	

		out >> *(pOther->m_Data);			
		if (!out) break;
		tmp.AddToTail(*(pOther->m_Data)); 

		delete pOther->m_Data;

	}
	
	other = tmp;
	return out;
}




List& List:: operator=(const List& other) {
	if (this != &other) {

		if (this->m_size == other.m_size) {
			this->Head = other.Head;				
		}

		else if (this->m_size < other.m_size) {
			for (int i = this->m_size; i < other.m_size; i++) {

			    	new Node(Tail.pPrev, other.Tail.m_Data);		
				m_size++;
			}
			this->Head = other.Head;
		}

		else if (this->m_size > other.m_size) {
			for (int i = other.m_size; i <= this->m_size; i++) {
				delete this->Head.pNext;
				m_size--;
			}
			this->Head = other.Head;
		}
	}
	return *this;
}

List& List::operator=(List&& m_oth)
{
	if (this != &m_oth) {
		while (Head.pNext != &Tail) {
			delete Head.pNext;
		}
		if (m_size) {

			m_size = m_oth.m_size;

			Head.pNext = m_oth.Head.pNext;
			Tail.pPrev = m_oth.Tail.pPrev;
			Head.pNext->pPrev = &Head;
			Tail.pPrev->pNext = &Tail;

			m_oth.Head.pNext = &m_oth.Tail;
			m_oth.Tail.pPrev = &m_oth.Head;
			m_oth.m_size = 0;
		}
	}

	return *this;
}