#include <iostream>

using namespace std;

class Student {
	string name;
public:
	Student(const string &n = "noName"):name(n){}
};

class Teacher {
	string name;
public:
	Teacher(const string &n="noName"):name(n){}
};

void addCourse(const Student &s) {

}

void addCourse(const Teacher &t) {

}

int main()
{
	addCourse(Teacher("Prof.DingleBerry"));
	return 0;
}

