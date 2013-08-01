#include "point.h"
#include "circle_inher.h"

Circle::Circle(const Point &p,double r):Point(p),radius(r) 
{
}

double Circle::getRadius() const 
{
	return radius;
}

Point Circle::getPoint() const
{
	return * static_cast<const Point*>(this);
}

double Circle::getArea() const 
{
	return radius*radius*Point::PI;
}

double Circle::getCircum() const
{
	return 2.0 * Point::PI *radius;
}

void Circle::moveTo(double a,double b)
{
	x = a; y = b;
}

void Circle::modifyRadius(double r)
{
	radius = r;
}
