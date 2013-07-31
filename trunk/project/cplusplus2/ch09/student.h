#include <iostream>

using namespace std;

class Student {
	const int id;
public:
	Student(int d):id(d) {
		cout << "student\n";
	}
	void print() {
		cout << id << endl;
	}
};

class Tutor {
	Student s;
public:
	Tutor(Student & st):s(st) {
		cout << "tutor\n";
		s.print();
	}
};

