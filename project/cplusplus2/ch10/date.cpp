//e0803.cpp
#include "date.h"
#include <cstdlib>

bool Date::isleapyear(int y) 
{
	return (y%400==0) || (y%4==0 && (y%100 != 0));
}

int Date::month_days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

void Date::setDate(int year,int month,int day)
{
	if (year < 0 || month <=0 || month > 12 || day <= 0) {
		exit(1);
	}
	int days = Date::month_days[month];
	if (Date::isleapyear(y)) {
		days ++;
	}
	if (day > days) {
		exit(1);
	}
	y = year;
	m = month;
	d = day;
}

Date::Date(int a,int b,int c)
{
	setDate(a,b,c);
}

Date & Date::operator++()
{
	int days = Date::month_days[m];
	if (Date::isleapyear(y) && (m==2)) {
		days++;
	}
	if (d++ == days) {
		d = 1;
		if (m++ == 12) {
			m = 1;
			y++;
		}
	}
	return *this;
}

Date Date::operator++(int ) 
{
	Date date(*this);

	int days = Date::month_days[m];
	if (Date::isleapyear(y) && (m==2)) {
		days++;
	}
	if (d++ == days) {
		d = 1;
		if (m++ == 12) {
			m = 1;
			y++;
		}
	}
	return date;
}


Date & Date::operator +=(int a)
{
	while (a > 0) {
		a--;
		++(*this);
	}
	while (a < 0) {
		a++;
		--(*this);
	}
	return *this;
}

Date & Date::operator--()
{
	if (--d == 0) {
		if (--m == 0) {
			y--;
			m = 12;
		}
		d = month_days[m];
		if ((m == 2) && Date::isleapyear(y)) {
			d++;
		}
	}
	return *this;
}

bool Date::operator<(const Date & s)
{
	return ((y << 12) + (m << 8) + d) < ((s.y << 12) + (s.m << 8) + s.d);
}

Date Date::operator +(int days)
{
	Date dt(*this);
	dt += days;
	return dt;
}

Date Date::operator -(int days)
{
	Date dt(*this);
	dt += (-days);
	return dt;
}

int Date::operator-(const Date & s)
{
	Date dt(*this);
	int r = 0;
	
	if (dt > s) {
		do {
			--dt;
			r++;
		} while(dt > s);
	} else if (dt < s) {
		do {
			++dt;
			r--;
		} while(dt < s);
	} else {
		cout << "equal\n";
	}
	return r;
}

bool Date::operator>(const Date & s)
{
	return ((y << 12) + (m << 8) + d) > ((s.y << 12) + (s.m << 8) + s.d);
}

bool Date::operator==(const Date & s)
{
	return (y == s.y && m == s.m && d == s.d);
}
