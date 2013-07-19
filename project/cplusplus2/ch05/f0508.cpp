#include <iostream>
#include <vector>

using namespace std;

typedef void (*MenuFun)();
void f1(){cout << "good\n";}
void f2(){cout << "better\n";}
void f3(){cout << "best\n";}

int main()
{
	MenuFun fun[]={f1,f2,f3};
	vector<MenuFun> vv(fun,fun+3);

	for (int choice=1;;choice) {
		cout << "1----display good\n" 
		     << "2----display better\n" 
                     << "3----display best\n" 
                     << "0---- exit\n"
		     << "Enter your choice:";
		cin >> choice;
		if (choice>=1 && choice<=3) {
			vv[choice-1]();
		} else if (choice == 0) {
			return 0;
		} else {
			cout << "Your entered a wrong key!\n";
		}
	}
	return 0;
}
