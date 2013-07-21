#include <iostream>
#include <sstream>
#include <fstream>
#include <stack>

using namespace std;

int main()
{
	ifstream in("rail.txt");
	for (int n,line=0;in>>n && n && in.ignore();) {
		cout << (line++?"\n":"");
		for (string s;getline(in,s)&&s!="0";) {
			istringstream sin(s);
			stack<int> st;
			for (int last=0,coatch;sin>>coatch;st.pop()) {
				for (int p=last+1;p<=coatch;p++) {
					st.push(p);
				}
				if (last < coatch) {
					last = coatch;
				}
				if (st.top() != coatch) {
					break;
				}
			}
			cout << (!sin ?"Yes":"No") << endl;
		}
	}
	return 0;
}
