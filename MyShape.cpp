#include "MyShape.h"
#include <iostream>

Shape::Shape(const Shape& other) {
	m_color = other.m_color;
}



Shape::~Shape() {
	
}

std::ostream& operator<<(std::ostream& out, const Shape& shape) {
	shape.print_screen(out);


    std::cout << " Area: " <<" " << shape.Area();
	return out;
}

std::ofstream& operator<<(std::ofstream& out, const Shape& shape) {

	shape.print_file(out);

	return out;
}

bool Shape::operator==(const Shape& shape) const { 
	if (typeid(*this) != typeid(shape)) {  
		return false; }
	else {
		return  sravnenie_figure(shape);
	}
}

std::ifstream& operator>>(std::ifstream& in, Shape& shape) {
	shape.read_file(in);
	return in;
}

Shape& Shape:: operator=(const Shape& other) {
	copy_figure(other);
	return *this;
}