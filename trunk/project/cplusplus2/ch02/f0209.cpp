#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	for (int i=1;i<=10;i++) {
		cout << setfill(' ')<<setw(i)<<" "
		     << setfill('M')<<setw(21-2*i)<<"M"<<endl;	
	}
	return 0;
}
