#include "ppoint.h"
#include <cmath>

using namespace std;

void PPoint::set(double ix,double iy)
{
	x = atan2(iy,ix);
	y = sqrt(ix*ix+iy*iy);
}

double PPoint::xOffset()
{
	return y*cos(x);
}

double PPoint::yOffset()
{
	return y*sin(x);
}

double PPoint::angle()
{
	return (180/3.1415926)*x;
}

double PPoint::radius()
{
	return y;
}

