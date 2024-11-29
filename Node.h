#pragma once
#include "MyShape.h"
#include <iostream>
#include <fstream>
class List;
class Node
{
	friend class List;

	Node* pPrev;		
	Node* pNext;		
	Shape* m_Data;


	Node() : pNext(nullptr), pPrev(nullptr) {  }
	Node(Node*, const Shape*);	 
	Node& operator=(const Node& d);

	friend std::ostream& operator<<(std::ostream& out, const List& other);

	friend std::ofstream& operator<<(std::ofstream& out, const List& shape);
	friend std::ifstream& operator>>(std::ifstream& os, List& other);
	~Node();

};