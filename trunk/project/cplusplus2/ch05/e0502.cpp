#include <iostream>

using namespace std;

const int n = 5;
const int m = 4;

int a[n][m];

void arrayinput();
void arraysum();
void arrayaverage();

int main()
{
#if 0
	//input
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> a[i][j];
		}
	}
	
	//total
	for (int i=0; i<n; i++) {
		int sum=0;
		for (int j=0; j<m;j++) {
			sum+=a[i][j];
		}
		cout << (i+1)<<"::" << sum << endl;
	}
	
	//average
	for (int i=0;i<n;i++) {
		int sum=0;
		for (int j=0;j<m;j++) {
			sum += a[i][j];
		}
		cout << "NO " << i << " average is " << double(sum)/n << endl;
	}
#else
	arrayinput();
	arraysum();
	arrayaverage();
#endif
	return 0;
}

void arrayinput() {
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> a[i][j];
		}
	}
	return ;
}
void arraysum(){
	for (int i=0; i<n; i++) {
		int sum=0;
		for (int j=0; j<m;j++) {
			sum+=a[i][j];
		}
		cout << (i+1)<<"::" << sum << endl;
	}
	return ;
}
void arrayaverage(){
	for (int i=0;i<n;i++) {
		int sum=0;
		for (int j=0;j<m;j++) {
			sum += a[i][j];
		}
		cout << "NO " << i << " average is " << double(sum)/n << endl;
	}
	return ;
}


