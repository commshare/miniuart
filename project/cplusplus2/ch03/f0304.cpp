#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
	char *s1="Hello ";
	char *s2="123";
	char a[20];
	
	strcpy(a,s1);
	cout<<(strcmp(a,s1)==0?"":"not ")<<"equal"<<endl;
	
	cout<<strcat(a,s2)<<endl;
//	cout<<strrev(a)<<endl;
//	cout<<strset(a,'c')<<endl;
	cout<<(strstr(s1,"ell")?"":"not ")<<"found"<<endl;
	cout<<(strchr(s1,'c')?"":"not ")<<"found"<<endl;
	return 0;
}
