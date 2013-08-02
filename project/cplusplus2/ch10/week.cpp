#include "week.h"

Week::Week(int a,int b,int c):Date(a,b,c)
{
	
};

enum WEEK getWeekday() const
{
	Date dt(*this);
	Date t(2013,8,2);
	
	int df = dt - t;
	
	cout << df 
	
}