//e0803.cpp
#include "date.h"

class Date {
	int y,m,d;
public :
	Date(int a,int b,int c):y(a),m(b),d(c){setDate(a,b,c);}
	Date & operator++();
	Date operator++(int);
	Date & operator +=(int);
	bool operator<(const Date & d);
	int operator-(const Date & d);
	friend ostream& operator<<(ostream &o, Date &d);
};
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


Date & operator +=(int a)
{
	while (a > 0) {
		a--;
		--(*this);
	}
	while (a < 0) {
		a++
		++(*this);
	}
	return *this;
}

Date & operator--()
{
		
}

bool operator<(const Date & s)
{
	return (y > s.y|| m > s.m || d > s.d);

}
int operator-(const Date & s)
{
	

}
