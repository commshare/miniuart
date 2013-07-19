#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc,char **argv)
{
	if (argc!=2) {
		cout << "Usage: f0512 command\n";
		return 1;
	}
	string s(argv[1]);
	istringstream sin(s);
	
	int a,b;char c;
	sin >> a >> c >> b;
	switch (c) {
		case '-': b=-b;
		case '+': cout << a+b; break;
		case '*': cout << a*b; break;
		case '/': cout << a/b; break;
		default: cout << "error";
	}
	cout << endl;
	return 0;
}
