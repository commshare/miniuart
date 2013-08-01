#include <iostream>
using namespace std;

class Advisor {
	int noOfMeeting;
public:
	Advisor() {cout << "Advisor\n";}
	Advisor(const Advisor & adv) {cout << "Copy Advisor\n";}
	~Advisor() {cout << "~Advisor\n";}
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
		cout << "name=\""<<name<<"\",hours="<<semesterHours
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
	GraduateStudent(const string &pN,const Advisor & adv):Student(pN),advisor(adv),qualifierGrade(0) {}
	int getQualifier () {
		return qualifierGrade;
	}
};

void fn(Advisor & advisor)
{
	GraduateStudent gs("Yen Kay Doogle",advisor);
	gs.display();
}

int main()
{
	Advisor da;
	fn(da);
	return 0;
}
