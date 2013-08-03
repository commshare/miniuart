#ifndef HEADER_WEEK
#define HEADER_WEEK

#include <string>
#include "date.h"


class WDate: public Date {
	static string WDateString[7];
public:
	WDate(int a=2000,int b=5,int c=8);
	int getWeekday() const;	
	friend ostream &operator <<(ostream & o,const WDate & wd);
};

inline ostream & operator<<(ostream &o,const WDate & wd)
{
	const Date & d = wd;
	int day;
	day = wd.getWeekday(); 
	return o << d << (wd.WDateString[day]);
}

#endif
