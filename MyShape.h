#pragma once
#include <fstream>

class Rect;
class Circle;
enum COLOR {WHITE, BLACK, RED, GREEN, BLUE };


class Shape {
	friend class List;
protected:

	COLOR m_color;

public:

	Shape() {
		m_color = BLACK;
	}

	Shape(COLOR color) {
		m_color = color;
	}

	Shape(const Shape& other);


	virtual double Area() const = 0;
	virtual Shape* clon() const = 0;   //ковариантный возвращаемый тип

	virtual ~Shape();

	friend std::ostream& operator<<(std::ostream& out, const Shape& shape);
	virtual void print_screen(std::ostream& out) const = 0;

	bool operator==(const Shape&) const;
	virtual bool sravnenie_figure(const Shape&) const = 0;

	Shape& operator=(const Shape& d);
	virtual void copy_figure(const Shape&)  = 0;
	
	
	friend std::ofstream& operator<<(std::ofstream& out, const Shape& shape);
	friend std::ifstream& operator>>(std::ifstream& os,Shape& other);
	virtual void print_file(std::ostream& out) const = 0;

	virtual void read_file(std::ifstream& os) = 0;
};