#include <iostream>
using namespace std;

class Advisor {
	int noOfMeeting;
};

class Student {
	string name;
	int semesterHours;
	double average;
public:
	Student(string pName="noNome"):name(pName),average(0),semesterHours(0) {}
	
	void addCourse(int hour,double grade) {
		double totalGrade = (semesterHours*average +grade);
		semesterHours += hour;
		average = semesterHours?(totalGrade/semesterHours):0;
	}
	
	void display() {
		cout << "name=\""<<name<<"\",hours"<<semesterHours
		     <<",average=" << average << endl;
	}
	
	int getHours() {
		return semesterHours;
	}
	
	double getAverage() {
		return average;
	}
};

class GraduateStudent: public Student {
	Advisor advisor;
	int qualifierGrade;
public:
	int getQualifier () {
		return qualifierGrade;
	}
};

int main()
{
	Student ds("Lo Lee undergrade");
	GraduateStudent gs;
	ds.addCourse(3,2.5);
	ds.display();
	gs.addCourse(3,3.0);
	gs.display();
		
	return 0;
}
