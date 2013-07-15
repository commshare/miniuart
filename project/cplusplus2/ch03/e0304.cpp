#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ifstream in("e0304.txt");
	vector<int> num;
	vector<string> ss;
	for (string s;getline(in,s);) {
		string m,y;
		istringstream sin(s);
		int d;
		sin>>m>>d>>y;
		if (d==25) {
			int f,n=1;
			f=y.find('*');
			if (f!=string::npos) {
				y.erase(f,1);
				n=2;
			}
			y=y+" "+m;
			int i;
			for(i=0;i<ss.size();i++) {
				if (ss[i]==y) {
					break;
				}
			}
			if (i != ss.size()) {
				num[i] += n;
			} else {
				ss.push_back(y);
				num.push_back(n);
			}
		}		
	}
	for (int i=0;i<ss.size();i++) {
		cout << ss[i] << ":"<<num[i]<<endl;
	}	
	return 0;
}
