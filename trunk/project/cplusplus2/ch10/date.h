//e0803.cpp
#ifndef HEADER_DATE
#define HEADER_DATE

#include <iostream>

using namespace std;

class Date {
	int y,m,d;
	Date::setDate(int year,int month,int day);
public :
	Date(int a=2000,int b=5,int c=8);
	Date & operator++();
	Date operator++(int);
	Date & operator +=(int);
	Date & operator -=(int);
	Date & operator--();
	Date operator--(int);
	int operator-(const Date & d);
	friend ostream& operator<<(ostream &o, Date &d);
};

inline ostream & operator<<(ostream &o,Date &d){
	o<<d.d<<"/"<<d.m<<"/"<<d.y<<std::endl;
}

#endif
