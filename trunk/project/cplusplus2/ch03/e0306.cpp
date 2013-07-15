#include <iostream>
using namespace std;

int main()
{
	int sum[5]={0};
	int iArray[]={1,4,2,7,13,32,21,48,16,30};
	int size=sizeof(iArray)/sizeof(iArray[0]);
	int *iPtr=iArray;
	
	for (int n=0;n<size;n++) {
		sum[3] += iPtr[n];
	}
 
	for (int n=0;n<size;n++) {
		sum[2] += *(iPtr+n);
	} 
	
	for (int n=0;n<size;n++) {
		sum[1] += *iPtr++;
	} 
	
	for (int n=0;n<size;n++) {
		sum[0] += iArray[n];
	} 
	
	
	for (int n=0;n<size;n++) {
		sum[4] += *(iArray+n);
	} 
	
	for (int n=0;n<5;n++) {
		cout<<sum[n]<<endl;
	} 
	
}
