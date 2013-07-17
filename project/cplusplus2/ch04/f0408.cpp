#include <iostream>
using namespace std;

char * myStrcpy(char * s1,const char *s2)
{
	char *s=s1;
	while (*s++ = *s2++);
	return s1;
}

int main()
{
	char a[50];
	const char *s="Hello ,I'm a student!\n";
	cout << myStrcpy(a,s);
	return 0;
}
