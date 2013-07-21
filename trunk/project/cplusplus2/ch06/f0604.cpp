#include <iostream>

using namespace std;

bool isnumber(char);

int main()
{
	char c;
	while (cin>>c) {
		if (isnumber(c)) {
			cout << "you entered a digit." << c << endl;
		} else {
			cout << "you entered a non-digit." << c << endl;
		}
	}
	return 0;
}

inline bool isnumber(char c)
{
	return ((c>='0')&&(c<='9'))?1:0;
}
