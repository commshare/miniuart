#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * only plus not minus
 * */
int add(int a[],int b[],int n)
{
	int f = 0,i;
	for (i=n-1;i >= 0;i--) {
		a[i] += b[i] + f;
		if (a[i] >= 10) {
			f = 1;
			a[i] -= 10;
		} else {
			f = 0;
		}
	}
	return 0;
}

int add_n(int a[],int x,int n)
{
	int f = 0,i;
	for (i=n-1;(i>=0) && x;i--) {
		a[i] += x%10 + f;
		if (a[i] >= 10) {
			f = 1;
			a[i] -= 10;
		} else {
			f = 0;
		}
		x/=10;
	}
	return 0;
}

void print(int a[],int n)
{
	int f = 0;
	for (int i=0;i < n;i++) {
		if (a[i] != 0) {
			f=1;
			printf("%d",a[i]);
		} else if ((a[i]==0) && f) {
			printf("0");
		}
	}
	printf("\n");
}

int main()
{
	FILE *fp;
	fp = fopen("e0608.txt","r");
	char bf[4096];
	int  a[1000];
	if (!fp) {
		return 1;
	}
	while (!feof(fp)) {
		char * p = bf;
		memset(bf,0,sizeof(bf));
		memset(a,0,sizeof(a));

		fscanf(fp,"%s",bf);
		if (strcmp("-1",bf) == 0) {
			break;
		}
		for (;*p;p++) {
			add(a,a,1000);
			add_n(a,*p-'0',1000);
		}
		print(a,1000);
	}
	if (fp) {
		fclose(fp);
	}
	return 0;
}
