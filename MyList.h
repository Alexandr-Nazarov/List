#pragma once
#include <iostream>
#include <fstream>

#include "Node.h"
#include "MyShape.h"
#include "MyCircle.h"
#include"MyRect.h"

enum SortType { AREA, COL };
class List
{

	//встроенное объявление класса Node

	//данные
	Node Head;	// фиктивный элемент, который является признаком начала списка
	Node Tail;	// фиктивный элемент, который является признаком конца списка
	size_t m_size;	//количество элементов
public:
	List() : m_size(0) {  Head.pNext = &Tail; Tail.pPrev = &Head; }

	List(const Shape&);
	~List();

	//конструкторы  присваивания, move
	List(const List& other);
	List(List&& other);
	List& operator=(const List& d);
	List& operator=(List&& d);


	void AddToHead(const Shape&);
	bool RemoveOne(const Shape&);
	void AddToTail(const Shape&);
	int RemoveAll(const Shape&);
	void ClearAll();
	void Sort(SortType);
	friend std::ostream& operator<<(std::ostream& os, const List& other);

	friend std::ofstream& operator<<(std::ofstream& out, const List& other); 
	friend std::ifstream& operator>>(std::ifstream& os,  List& other);
};

