#include <iostream>

using namespace std;

class Point{
	int x,y;
public:
	void set(int a,int b) {x=a;y=b;}
	void print() const {
		cout << "(" <<x << "," << y << ")\n";
	}
	Point operator+(const Point &b);
	friend Point add(const Point &a,const Point &b);
};

Point Point::operator+(const Point &b)
{
	Point s;
	s.set(x+b.x,y+b.y);
	return s;
}

Point add(const Point &a,const Point &b) 
{
	Point s;
	s.set(a.x+b.x,a.y+b.y);
	return s;
}

int main()
{
	Point a,b;
	a.set(2,5);
	b.set(3,1);

	(a+b).print();
	a.operator+(b).print();
	add(a,b).print();

	return 0;
}

