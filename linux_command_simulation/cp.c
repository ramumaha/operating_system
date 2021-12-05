#include <stdlib.h>
#include<stdio.h>
int main()
{
	FILE *f1, *f2;
	char file1[20], file2[20], dummy;
	printf("enter the filename to read: ");
	scanf("%s", file1);
	f1 = fopen(file1, "r");
	
	if(f1==NULL)
	{
		printf("File Not found!");
		exit(0);
	}

	printf("Enter the filename to write: ");
	scanf("%s", file2);
	f2 = fopen(file2, "w");
	
	if (f2==EOF) 
	{
		printf("File Not Found!");
		exit(0);
	}

	dummy = fgetc(f1);
	while (dummy != -1 )
	{
		fputc(dummy, f2);
		dummy = fgetc(f1);
	}
	
	printf("file copied to %s\n", file2);
	fclose(f1);
	fclose(f2);
}