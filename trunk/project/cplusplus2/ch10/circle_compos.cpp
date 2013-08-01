#include "point.h"
#include "circle_compos.h"

Circle::Circle(const Point &p,double r):point(p),radius(r) 
{
}

double Circle::getRadius() const 
{
	return radius;
}

Point Circle::getPoint() const
{
	return point;
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
	point.moveTo(a,b);
}

void Circle::modifyRadius(double r)
{
	radius = r;
}
