#include "Node.h"

Node::Node(Node* p, const Shape* pc) 
{   

	if(pc)
	m_Data = pc->clon();

	pPrev = p;
	pNext = p->pNext;

	p->pNext = this;
	pNext->pPrev = this;

}

Node::~Node()
{
	delete m_Data; // добавил из-за clon()

	//»зъ€ли текущий элемент из списка
	//коррекци€ следующего
	if (pNext != 0) pNext->pPrev = this->pPrev;
	//коррекци€ предыдущего
	if (pPrev != 0) pPrev->pNext = this->pNext;
}

Node& Node:: operator=(const Node& other) {   
	if (this != &other) {
		Node* pOther1 = this->pNext;
		Node* pOther2 = other.pNext;
		while (pOther2->pNext) {
			
			if (pOther1->m_Data) {
				if (typeid(*(pOther1->m_Data)) == typeid(*(pOther2->m_Data))) {
					*(pOther1->m_Data) = *(pOther2->m_Data);
			
				}
				else {
					delete pOther1->m_Data;
					pOther1->m_Data = pOther2->m_Data->clon();
				}
			}
			else {
				delete pOther1->m_Data;
				pOther1->m_Data = pOther2->m_Data->clon();
			}
			
		
			pOther2 = pOther2->pNext;
			pOther1 = pOther1->pNext;
		}
	}
	return *this;
}