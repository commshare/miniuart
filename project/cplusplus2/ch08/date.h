//e0803.cpp
#ifndef HEADER_DATE
#define HEADER_DATE

#include <iostream>

using namespace std;

class Date {
	int y,m,d;
public :
	Date & operator++();
	Date operator++(int);
	void setDate(int,int,int);
	friend ostream& operator<<(ostream &o, Date &d);
};

inline ostream & operator<<(ostream &o,Date &d){
	o<<d.d<<"/"<<d.m<<"/"<<d.y<<std::endl;
}

#endif
