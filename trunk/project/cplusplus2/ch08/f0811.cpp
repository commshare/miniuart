#include "ppoint.h"
#include <iostream>

using namespace std;

int main()
{
	PPoint p;
	for (double x,y;cout <<"Enter x and y:\n"&& cin >>x>> y && x>=0;) {
		p.set(x,y);
		cout << "angle="<<p.angle() << ",radius="<<p.radius()
		     << ",x offset=" <<p.xOffset()<<",y offset="<<p.yOffset()<<"\n";
	}
}