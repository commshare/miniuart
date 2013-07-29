#include "point.h"

void Point::set(int a,int b) 
{
	x=a,y=b;
}

Point Point::operator+(const Point &d)
{
	Point s;
	s.set(d.x,d.y);
	return s;
}
