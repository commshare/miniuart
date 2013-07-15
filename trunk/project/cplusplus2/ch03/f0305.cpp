#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
	string a,s1="Hello ";
	string s2="123";
	a=s1;
	cout<<(a==s1?"":"not ")<<"equal"<<endl;
	cout<<a+s2<<endl;
	reverse(a.begin(),a.end());
	cout<<a<<endl;
	cout<<a.replace(0,9,9,'c')<<endl;
	cout<<(s1.find("ell")!=-1?"":"not ")<<"found"<<endl;
	cout<<(s1.find('c') != -1 ? "":"not ")<<"found"<<endl;
	return 0;
}
