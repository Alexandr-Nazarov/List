#pragma once
#include <fstream>
#include "MyShape.h"


class Circle :public Shape {
	int m_x, m_y, m_radius;
public:
	Circle() : Shape(GREEN)
	{
		m_x = 0; m_y = 0; m_radius = 0;

	}
	Circle(int Xord, int Yord, int Radius, COLOR color) : Shape(color)
	{
		m_x = Xord; m_y = Yord; m_radius = Radius;
	}


	Circle(const Circle& other);

	virtual double Area() const;
	virtual Circle* clon() const { return new Circle(*this); }   //ковариантный возвращаемый тип

	virtual ~Circle(); 


	virtual void print_screen(std::ostream& out) const;

	virtual bool sravnenie_figure(const Shape&) const;

	virtual void print_file(std::ostream& out) const;

	virtual void read_file(std::ifstream& os);

	virtual void copy_figure(const Shape&) ;
};