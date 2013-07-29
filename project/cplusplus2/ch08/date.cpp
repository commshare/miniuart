//e0803.cpp
#include "date.h"

static bool isleapyear(int y) 
{
	return (y%400==0) || (y%4==0 && (y%100 != 0));
}

static int month_days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

void Date::setDate(int year,int month,int day)
{
	if (year < 0 || month <=0 || month > 12 || day <= 0) {
		exit(1);
	}
	int days = month_days[month];
	if (isleapyear(y)) {
		days ++;
	}
	if (day > days) {
		exit(1);
	}
	y = year;
	m = month;
	d = day;
}

Date& Date::operator++() 
{
	int days = month_days[m];
	if (isleapyear(y)) {
		days++;
	}
	if (d == days) {
		d = 1;
		if (m++ == 13) {
			m = 1;
			y++;
		}
	} else {
		d++;
	}
	return *this;
}


Date Date::operator++(int ) 
{
	Date date(*this);

	int days = month_days[m];
	if (isleapyear(y)) {
		days++;
	}
	if (d == days) {
		d = 1;
		if (m++ == 13) {
			m = 1;
			y++;
		}
	} else {
		d++;
	}
	return date;
}


