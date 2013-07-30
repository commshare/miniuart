#ifndef HEADER_PPOINT
#define HEADER_PPOINT

class PPoint {
	double x,y;
public:
	PPoint(double ix,double iy);
	double xOffset();
	double yOffset();
	double angle();
	double radius();
};

#endif
