#include <stdio.h>
#include <string.h>

int cnt(const char *a)
{
	int num = 0;
	while(*a) {
		if (*a++ == '1') {
			num++;
		}
	}
	return num;
}

int main()
{
	FILE * fp = fopen("string.txt","r");
	while (1) {
		char a[1025],b[1025];
		fscanf(fp,"%s",a);
		fscanf(fp,"%s",b);
		
		if (feof(fp)) break;
		printf("%s",(strlen(a)==strlen(b) && cnt(a)==cnt(b) ? "yes\n":"no\n"));
	}
	if (fp){
		fclose(fp);
	}
	return 0;
}
