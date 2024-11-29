#include "MyCircle.h"
#include <cmath>
#include <iostream>

Circle::Circle(const Circle& other) :Shape(other) {
	m_x = other.m_x;
	m_y = other.m_y;
	m_radius = other.m_radius;
	m_color = other.m_color;
}



Circle::~Circle() {

}

double Circle::Area() const {
	double area;
	area = 3.14 * (std::pow(m_radius,2));
	return area;
}



 void Circle::print_screen(std::ostream& out) const {
	out <<  m_x << " " << m_y << " " << m_radius << " " << m_color;
}

bool Circle::sravnenie_figure(const Shape& shape) const {
	const Circle* circle = static_cast<const Circle*>(&shape);
    return (((this->m_x == circle->m_x) && (this->m_y == circle->m_y) && (this->m_radius == circle->m_radius) && (this->m_color == circle->m_color)) == 1);
}

void Circle::print_file(std::ostream& out) const {
	out << "c" << " " << m_x << " " << m_y << " " << m_radius << " " << m_color;
}

void Circle::read_file(std::ifstream& os) {
	os >> m_x;
	os >> m_y;
	os >> m_radius;
	int tmp_color;
	os >> tmp_color;
	m_color = static_cast<COLOR>(tmp_color);
}

void Circle::copy_figure(const Shape& shape)  {
	const Circle* circle = static_cast<const Circle*>(&shape);
	this->m_x = circle->m_x;
	this->m_y = circle->m_y;
	this->m_radius = circle->m_radius;
	this->m_color = circle->m_color;

}