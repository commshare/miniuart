#include <iostream>

using namespace std;

typedef void (*MenuFun)();
void f1(){cout << "good\n";}
void f2(){cout << "better\n";}
void f3(){cout << "best\n";}


int main()
{
	MenuFun fun[]={f1,f2,f3};
	for (int choice=1;;choice) {
		cout << "1----display good\n" 
		     << "2----display better\n" 
                     << "3----display best\n" 
                     << "0---- exit\n"
		     << "Enter your choice:";
		cin >> choice;
		switch(choice) {
			case 1:fun[0](); break;
			case 2:	fun[1](); break;
			case 3:	fun[2]();break;
			case 0:	return 0;
			default : cout << "Your entered a wrong key!\n";
		}
	}
	return 0;
}
