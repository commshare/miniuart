#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int count(unsigned int a)
{
	int sum=0;
	unsigned int x;
	for (x=a;x;x>>=1) {
		if (x&1) { 
			sum++;
		}
	}
	return sum;
}

int sieve(unsigned int *p)
{
	int i,j;
	for ( i=2;i<=10000;i++) {
		if (p[i/32] & (1<<(i%32))) {
			for (j=i*i;j<100000000;j+=i) {
				p[j/32] &= ~(1<<(j%32));
			}
		}
	}
}

int main()
{
	int num = -2,i;
	clock_t start = clock();
	unsigned int *p = (unsigned int*)malloc(12500000);

	if (!p) {
		printf("no enough memory.\n");
		return 1;
	}
	memset(p,255,12500000);
	sieve(p);
	
	for (i=0; i<(12500000/4); i++){
		num += count(p[i]);
	}
	free(p);
	printf("%d,%7.3f\n",num,(clock()-start)/(CLOCKS_PER_SEC*1.0));
	return 0;
}
