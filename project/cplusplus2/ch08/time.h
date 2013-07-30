#ifndef HEADER_TIME
#define HEADER_TIME

#include <iostream>
using namespace std;

class Time {
	int hour,minute,second;
public:
	void set(int h,int m,int s);
	friend ostream & operator<<(ostream &o,const Time &t);
};

#endif
