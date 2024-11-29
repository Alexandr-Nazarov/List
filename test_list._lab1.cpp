//------------------------------------------------------------------------------
// Тестируем разработанный список
//------------------------------------------------------------------------------
#include <iostream>
#include <tchar.h>
#include <typeinfo>

#include "MyShape.h"
#include "MyRect.h"
#include "MyCircle.h"
#include "Node.h"
#include "MyList.h"

const char* sep = "------------------------------------\n";


int _tmain(int argc, _TCHAR* argv[])
{
	//
	// 1. Создаем список
	//
	List ls1;
	
	ls1.AddToTail(Circle(1, 1, 1, WHITE));	
	ls1.AddToTail(Circle(5, 5, 5, RED));
	ls1.AddToTail(Rect(2, 3, 4, 5, RED));
	ls1.AddToTail(Rect(4, 6, 8, 10, GREEN));
	ls1.AddToTail(Circle(2, 2, 2, WHITE));
	ls1.AddToTail(Rect(3, 5, 6, 7, GREEN));
	std::cout << ls1;							

	ls1.RemoveOne(Circle(5, 5, 5, RED));		// удаляем первый элемент, равный заданному
	std::cout << ls1; 
	ls1.RemoveOne(Rect(4, 6, 8, 10, GREEN));
	std::cout << ls1;

	std::cout << "2:\n"<<sep;
	List ls2 = ls1;	
	List ls3 = ls2;
	std::cout << ls2; 

	ls2.AddToHead(Circle(5, 5, 5, RED));
	ls2.AddToHead(Rect(5, 7, 9, 11, WHITE));
	
	std::cout << ls2;	
	ls1 = ls2;			// из "большого" списка в "маленький"
	std::cout << ls1;	
	
	ls1 = ls3;			// из "маленького" списка в "большой"
	std::cout << ls1 << sep;	

	List ls4 = std::move(ls2);
	std::cout << ls4; 
	std::cout << ls2; 	

	ls3 = std::move(ls4);
	std::cout << ls3; 
	std::cout << ls4 << sep;
	//
	//  Сортировка по возрастанию площади кружка
	//
	std::cout << ls3;
	ls3.Sort(AREA);
	std::cout << ls3 << sep;

	ls3.Sort(COL);
	std::cout << ls3 << sep;

	//
	// 5. Файловый ввод/вывод
	//
	

	std::ofstream fout("list.txt");
	ls3.AddToHead(Rect(5, 7, 9, 11, WHITE));
	ls3.AddToHead(Circle(5, 5, 5, RED));
	fout << ls3;	// выводим список в файл
	fout.close();

	

	std::ifstream fin("list.txt");
	List ls5;		// читаем список из файла
	fin >> ls5;
	fin.close();
	
	std::cout << ls5;
	 

	return 0;
}