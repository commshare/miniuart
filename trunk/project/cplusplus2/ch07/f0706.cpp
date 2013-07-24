#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int row=100;
const int col=100;

int main()
{
	ifstream in("f0706.txt");
	int ma[row][col];
	int mb[row][col];
	int mc[row][col];	
	for (int r,c;in>>r>>c;) {
		for (int i=0;i<r;i++) {
			for(int j=0;j<c;j++) {
				in>>ma[i][j];
			}
		}

		for (int i=0;i<r;i++) {
			for(int j=0;j<c;j++) {
				in>>mb[i][j];
			}
		}

		for (int i=0;i<r;i++) {
			for(int j=0;j<c;j++) {
				mc[i][j] = ma[i][j] + mb[i][j];
			}
		}

		for (int i=0;i<r;i++) {
			for(int j=0;j<c;j++) {
				cout << setw(4) << mc[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}



