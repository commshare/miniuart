#ifndef HEADER_WEEK
#define HEADER_WEEK

#include "date.h"
enum WEEK {
	SUNDAY = 0;
	MONDAY;
	TUESDAY;
	WEDNESDAY;
	THURSDAY;
	FRIDAY;
	SATURDAY;
};

class Week: public Date {
public:
	Week(int a=2000,int b=5,int c=8);
	enum WEEK getWeekday() const;
};

#endif