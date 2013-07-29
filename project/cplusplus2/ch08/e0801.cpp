#include <cmath>
#include <iostream>
using namespace std;

class Point {
protected:
	double x;
	double y;
public:
	void Set(double ix,double iy) 
	{
		x = ix; y = iy;
	}
	
	double xOffset() 
	{
		return x;
	}

	double yOffset() 
	{
		return y;
	}

	double angle()
	{
		return (180/3.141592)*atan2(y,x);
	}

	double radius() 
	{
		return sqrt(x*x+y*y);
	}
};

int main()
{
	Point p;
	double x,y;
	
	cout << "Enter x and y:\n";
	cin >> x >> y;

	p.Set(x,y);
	x += 5;//p.x += 5;
	y += 6;//p.y += 6;
	p.Set(x,y);
	
	cout << "angle=" << p.angle()
	     << ",radius=" << p.radius()
	     << ",x offset=" << p.xOffset()
	     << ",y offset=" << p.yOffset() << endl;
	return 0;
}
