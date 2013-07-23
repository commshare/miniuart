#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool foo1(string & s)
{
	for (int i=0,j = s.length()-1;i < j;i++,j--) {
		if (s[i] != s[j]) {
			if ((s[i] <= 'z') && (s[i] >= 'a')) {
				if ((s[j] - 'A' + 'a') != s[i])
					return false;
			} else if ((s[i] <= 'Z') && (s[i] >= 'A')) {
				if ((s[j] - 'a' + 'A') != s[i]) {
					return false;
				}
			} else {
				switch (s[i]) {
				case '<':
					if (s[j] != '>') return false;
					break;
				
				case '[':
					if (s[j] != ']') return false;
					break;
				
				case '{':
					if (s[j] != '}') return false;
					break;
				
				case '(':
					if (s[j] != ')') return false;
					break;
				
				case '>':
					if (s[j] != '<') return false;
					break;
				
				case ']':
					if (s[j] != ']') return false;
					break;
				
				case '}':
					if (s[j] != '}') return false;
					break;
				
				case ')':
					if (s[j] != ')') return false;
					break;
				default:
					return false;
				}
			}
		}
	}
	return true;
}

int main()
{
	ifstream in("e0607.txt");
	for(string s;getline(in,s);) {
		if (s=="00000") {
			break;
		}
		cout << (foo1(s) ? "Symmetry":"Not symmetry") << endl;		
	}
	return 0;
}
