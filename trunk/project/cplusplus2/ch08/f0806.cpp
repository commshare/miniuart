#include <iostream>
#include <iomanip>
using namespace std;

class Time {
	int hour,minute,second;
public:
	void set(int h,int m,int s) {
		hour = h,minute = m,second=s;
	}
	friend Time& operator++(Time& a);
	friend Time operator++(Time &a,int);
	friend ostream& operator<<(ostream& o,const Time & t);
};


Time & operator++(Time &a)
{
	if (!(a.second=(a.second+1)%60) && !(a.minute=(a.minute+1)%60)) {
		a.hour = (a.hour+1)%24;
	}
	return a;
}

Time operator++(Time &a,int )
{
	Time t(a);
	if (!(a.second=(a.second+1)%60) && !(a.minute=(a.minute+1)%60)) {
		a.hour = (a.hour+1)%24;
	}
	return t;
}

ostream & operator<<(ostream &o,const Time &t)
{
	o<<setfill('0')<<setw(2)<<t.hour<<":"<<setw(2)<<t.minute<<":"
	 <<setw(2)<<t.second<<"\n"<<setfill(' ');
	return o;
}


int main()
{
	Time t;
	t.set(11,59,58);
	cout<<t;
	cout<<t++;
	cout<<++t;
	return 0;
}









