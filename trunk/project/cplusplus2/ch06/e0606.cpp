#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>

#define pai 3.1415926

using namespace std;

void foo1(vector<vector<int> > & v,char ch)
{
	for (int i = 0; i < v.size();i++) {
		for (int j=0;j < v[i].size();j++) {
			cout << (v[i][j] ? ch :' ');
		}
		cout << endl;
	}
	cout << endl;
}


/*
 *y = b*sin(pai/2a * x) + b;
 * */

int main()
{
	ifstream in("e0606.txt");

	for(string s;getline(in,s);) {
		istringstream sin(s);
		int x,y;
		char ch;
		sin >> x >> y >> ch;
		
		vector<vector<int> > vc;
		for(int i=0;i<2*y-1;i++) {
			vector<int> v(4*x+1,0);
			vc.push_back(v);
		}

		for (int i=0;i<4*x+1;i++) {
			int j;
			j = int(y*(std::sin(pai/(-x*2.0) * i))) + y;
			if ((j < 2*y-1) && (j>=0)) {
				vc[j][i] = 1;
			}
			if (abs(j-0) < 1e-2) {
				vc[0][i] = 1;
			}

			if (abs(j-(2*y-1)) < 1e-2) {
				vc[2*y-2][i] = 1;
			}
		}
		foo1(vc,ch);
	}
	return 0;
}
