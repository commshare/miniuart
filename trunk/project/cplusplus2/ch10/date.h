//e0803.cpp
#ifndef HEADER_DATE
#define HEADER_DATE

#include <iostream>

using namespace std;

class Date {
	int y,m,d;
	void setDate(int year,int month,int day);
protected:
	static bool isleapyear(int y);
	static int month_days[13];
public :
	Date(int a=2000,int b=5,int c=8);
	Date & operator++();
	Date operator++(int);
	Date & operator +=(int);
	Date operator +(int);
	Date operator -(int days);
	Date & operator--();
	int operator-(const Date & s);
	bool operator<(const Date & s);
	bool operator>(const Date & s);
	bool operator==(const Date & s);
	friend ostream& operator<<(ostream &o,const Date &d);
};

inline ostream & operator<<(ostream &o,const Date &d){
	return o<<d.d<<"/"<<d.m<<"/"<<d.y <<" ";
}

#endif
