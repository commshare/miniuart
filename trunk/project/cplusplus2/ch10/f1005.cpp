#include "circle_inher.h"
#include <iostream>

using namespace std;

int main()
{
	Point a(2.3,5.6);
	Circle c(a,7);
	
	c.moveTo(1,2);
	c.modifyRadius(3);

	cout << "The radius is " << c.getRadius() << endl;
	cout << "The point is " << c.getPoint();
	cout << "The area is " << c.getArea() << endl;
	cout << "The circumference is " << c.getCircum() << endl;
	
	return 0;
}
