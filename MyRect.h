#pragma once
#include "MyShape.h"


class Rect :public Shape {

	int m_top_x, m_top_y, m_bottom_x, m_bottom_y;				//top- левый, bottom-правый
public:
	Rect() : Shape(RED)
	{
		m_top_x = 0; m_top_y = 0; m_bottom_x = 0, m_bottom_y = 0;
	//	m_color = RED;

	}
	Rect(int top_x, int top_y, int bottom_x, int bottom_y, COLOR color) : Shape(color)
	{
		norm_Rect(top_x, top_y, bottom_x, bottom_y);


	}

	Rect(const Rect& other);

	void norm_Rect(int, int, int, int);

	virtual double Area() const;

	virtual Rect* clon() const { return new Rect(*this);}		//ковариантный возвращаемый тип

	virtual void print_screen(std::ostream& out) const;

	virtual bool sravnenie_figure(const Shape&) const;
	
	virtual void print_file(std::ostream& out) const;

	virtual void read_file(std::ifstream& os);

	virtual void copy_figure(const Shape&) ;

	virtual ~Rect(); 
};

