#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


int main()
{
	for (int i=1;i<=10;i++) {
		cout << string(i,' ') << string(21-2*i,'M')<<endl; 
	}
	return 0;
}
