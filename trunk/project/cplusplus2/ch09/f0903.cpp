#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

class Date {
	int year,month,day;
public:
	Date(int y=2000,int m=1,int d=1);
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

Date::Date(int y,int m,int d) 
{
	year =y;
	month = m;
	day = d;
}

Date::Date(const string& s)
{
	year = atoi(s.substr(0,4).c_str());
	month = atoi(s.substr(5,2).c_str());
	day = atoi(s.substr(8,2).c_str());
}

ostream &operator<<(ostream &o,const Date & d)
{
	return o<<setfill('0')<<setw(4)<<d.year<<'-'<<setw(2)<<d.month<<'-'<<setw(2)<<d.day<<'\n';
}

bool Date::isLeapYear() const
{
	return (year%4==0 && year%100 !=0) || (year % 400 == 0);
}
