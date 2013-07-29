#include <iostream>
#include <string>
using namespace std;

class Student {
	static int n;
	string name;
public:
	void set(string str) {
		static int number;
		name = str;
		n = ++number;
	}

	void print() {
		cout << name <<"->students are "<<n<<" numbers\n";
	}
};

int Student::n=0;

void fn()
{
	Student s1;
	s1.set("Jenny");
	Student s2;
	s2.set("Randy");
	s1.print();
}

int main()
{
	Student s;
	s.set("Smith");
	fn();
	s.print();
	
	return 0;
}
