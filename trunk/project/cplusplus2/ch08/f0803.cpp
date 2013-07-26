#include <iostream>
#include <iomanip>
using namespace std;

class Date {
	int year,month,day;
public :
	void set(int y,int m,int d);
	void print();
	bool isLeapYear();
};

int main()
{
	Date *d = new Date;
	d->set(2000,12,6);
	if (d->isLeapYear()) {
		d->print();
	}
	return 0;
}

void Date::set(int y,int m,int d) 
{
	year =y;
	month = m;
	day = d;
}

void Date::print()
{
	cout<<setfill('0')<<setw(4)<<year<<'-'<<setw(2)<<month<<'-'<<setw(2)<<day<<'\n';
}

bool Date::isLeapYear()
{
	return (year%4==0 && year%100 !=0) || (year % 400 == 0);
}
