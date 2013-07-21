#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	ifstream in("rail.txt");
	for (int n,line=0;in>>n && n && in.ignore();) {
		cout << (line++?"\n":"");
		for (string s;getline(in,s)&&s!="0";) {
			istringstream sin(s);
			vector<int> st;
			for (int last=0,coatch;sin>>coatch;st.erase(st.begin())) {
				for (int p=last+1;p<=coatch;p++) {
					st.insert(st.begin(),p);
				}
				if (last < coatch) {
					last = coatch;
				}
				if (st[0] != coatch) {
					break;
				}
			}
			cout << (!sin ?"Yes":"No") << endl;
		}
	}
	return 0;
}
