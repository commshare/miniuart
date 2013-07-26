#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Date {
	int year,month,day;
public :
	void set(int y,int m,int d);
	void set(string s);
	void print();
	bool isLeapYear();
};

int main()
{
	Date d,e;
	d.set(2000,12,6);
	e.set("2005-05-05");
	e.print();

	if (d.isLeapYear()) {
		d.print();
	}
	return 0;
}

void Date::set(int y,int m,int d) 
{
	year =y;
	month = m;
	day = d;
}

void Date::set(string s)
{
	year = atoi(s.substr(0,4).c_str());
	month = atoi(s.substr(5,2).c_str());
	day = atoi(s.substr(8,2).c_str());
}
void Date::print()
{
	cout<<setfill('0')<<setw(4)<<year<<'-'<<setw(2)<<month<<'-'<<setw(2)<<day<<'\n';
}

bool Date::isLeapYear()
{
	return (year%4==0 && year%100 !=0) || (year % 400 == 0);
}
