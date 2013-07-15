#include <iostream>

using namespace std;


int main()
{
	cout<<("join"=="join"?"":"not ")<<"equal"<<endl;	
	char *str1="good";
	char *str2="good";
	cout<<(str1==str2?"":"not ")<<"equal"<<endl;

	char buffer1[6]="hello";
	char buffer2[6]="hello";
	cout<<(buffer1==buffer2?"":"not ")<<"equal"<<endl;
	return 0;
}
