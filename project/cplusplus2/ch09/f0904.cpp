#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

class Date {
	int y,m,d;
	void init();
public:
	Date(int year=2000,int month=1,int day=1);
	Date(const string &s);
	bool isLeapYear() const;
	friend ostream &operator<<(ostream &o,const Date &);

};

int main()
{
	Date c("2005-12-28");
	Date d(2000,12,6);
	Date e(2000);
	Date f(2002,12);
	Date g;
	cout << c << e << f << g ;
	return 0;
}

void Date::init()
{
	if (y > 5000 || y < 1 || m < 1 || m > 12 || d < 1 || d > 31) {
		exit(1);
	}
}

Date::Date(int year,int month,int day) 
{
	y =year;
	m = month;
	d = day;
	init();
}

Date::Date(const string& s)
{
	y = atoi(s.substr(0,4).c_str());
	m = atoi(s.substr(5,2).c_str());
	d = atoi(s.substr(8,2).c_str());
	init();
}

ostream &operator<<(ostream &o,const Date & d)
{
	return o<<setfill('0')<<setw(4)<<d.y<<'-'<<setw(2)<<d.m<<'-'<<setw(2)<<d.d<<'\n';
}

bool Date::isLeapYear() const
{
	return (y%4==0 && y%100 !=0) || (y % 400 == 0);
}
