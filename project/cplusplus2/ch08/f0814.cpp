#include <iostream>
#include <string>
using namespace std;

class Student {
	static int number;
	string name;
public:
	void set(string str) {
		name = str;
		++number;
	}

	static void printNumber() {
		cout << number <<" total numbers.\n";
	}

	static void printNumber(Student &s) {
		cout << "My name is " << s.name << endl;
		cout << s.number << " total numbers.\n";
	}
	
	
	void print() {
		cout << name <<"->students are "<<number<<" numbers\n";
	}
};

int Student::number=0;

void fn()
{
	Student s1;
	s1.set("Jenny");
	Student s2;
	s2.set("Randy");
	s1.printNumber();
}

int main()
{
	Student s;
	s.set("Smith");
	fn();
	Student::printNumber();
	
	Student::printNumber(s);
	
	return 0;
}
