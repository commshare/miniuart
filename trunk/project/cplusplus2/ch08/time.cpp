#include "time.h"
#include <iomanip>
#include <iostream>
using namespace std;

void Time::set(int h,int m,int s)
{
	hour = h;
	minute = m;
	second = s;
}

ostream & operator<<(ostream &o,const Time & t)
{
	return o << setfill('0') << setw(2) << t.hour <<':' 
		 << setw(2) << t.minute <<':'<< setw(2) << t.second
		 << endl << setfill(' ');
}
