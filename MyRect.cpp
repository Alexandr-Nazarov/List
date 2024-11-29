#include "MyRect.h"
#include <iostream>


Rect::Rect(const Rect& other) :Shape(other) {
	m_top_x = other.m_top_x;
	m_top_y = other.m_top_y;
	m_bottom_x = other.m_bottom_x;
	m_bottom_y = other.m_bottom_y;
	m_color = other.m_color;
}

Rect::~Rect() {
	
}

void Rect::norm_Rect(int left, int top, int right, int bottom)
{

	if (left <= right) {
		m_top_x = left; m_bottom_x = right;
	}
	else { int tmp = left; m_top_x = right; m_bottom_x = tmp; }			

	if (top <= bottom) {
		m_top_y = top; m_bottom_y = bottom;
	}
	else { int tmp = top; m_top_y = bottom; m_bottom_y = tmp; }

}


double Rect::Area() const{
	double area;
	area = (m_bottom_x-m_top_x)*(m_bottom_y-m_top_y);
	return area;
}

void Rect::print_screen(std::ostream& out) const {
	out  << m_top_x << " " << m_top_y << " " << m_bottom_x << " " << m_bottom_y << " " << m_color;
}

bool Rect::sravnenie_figure(const Shape& shape) const {
	const Rect* rect = static_cast<const Rect*>(&shape);
	
	return (((this->m_top_x == rect->m_top_x) && (this->m_top_y == rect->m_top_y)
		     && (this->m_bottom_x == rect->m_bottom_x) && (this->m_bottom_y == rect->m_bottom_y) && (this->m_color == rect->m_color))  == 1);
}

void Rect::print_file(std::ostream& out) const {
	out << "r" << " " << m_top_x << " " << m_top_y << " " << m_bottom_x << " " << m_bottom_y << " " << m_color;
}

void Rect::read_file(std::ifstream& os) {
	os >> m_top_x;
	os >> m_top_y;
	os >> m_bottom_x;
	os >> m_bottom_y;
	int tmp_color;
	os >> tmp_color;
	m_color = static_cast<COLOR>(tmp_color);
}

void Rect::copy_figure(const Shape& shape) {
	const Rect* rect = static_cast<const Rect*>(&shape);
	this->m_bottom_x = rect->m_bottom_x;
	this->m_bottom_y = rect->m_bottom_y;
	this->m_top_x = rect->m_top_x;
	this->m_top_y = rect->m_top_y;
	this->m_color = rect->m_color;

}