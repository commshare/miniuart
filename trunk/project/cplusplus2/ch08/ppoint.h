#ifndef HEADER_PPOINT
#define HEADER_PPOINT

class PPoint {
	double x,y;
public:
	void set(double ix,double iy);
	double xOffset();
	double yOffset();
	double angle();
	double radius();
};

#endif
