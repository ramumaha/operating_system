#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int choice;
	printf("\nEnter your choice(1-10): ");
	printf("\n1. ls");
	printf("\n2. cat");
	printf("\n3. pwd");
	printf("\n4. clear");
	printf("\n5. ps");
	printf("\n6. cal");
	printf("\n7. date");
	printf("\n8. man");
	printf("\n9. cp");
	printf("\n10. rm");
	printf("\nEnter your Choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: printf("\nEnter Filename1, Filename2, and Dirname: "); 
			char filename1[20],filename2[20],dirname[20]; 
			scanf(" %s %s %s",filename1,filename2,dirname); 
			execl("/bin/ls","ls","-l",filename1,filename2,dirname,NULL); 
			break;
		case 2: printf("\nEnter File Name: "); 
			char filename[20];
			scanf(" %s",filename);
			execl("/bin/cat","cat",filename,NULL); 
			break;
		case 3: execl("/bin/pwd","pwd",NULL);	break;
		case 4: execl("/bin/clear","clear",NULL);	break;
		case 5: execl("/bin/ps","ps","-e",NULL);	break;
		case 6: execl("/bin/cal","cal",NULL);	break;
		case 7: execl("/bin/date","date",NULL);	break;
		case 8: printf("\nEnter Command Name: "); 
			char comname[20]; scanf(" %s",comname);
			execl("/bin/man","man",comname,NULL); 
			break;
		case 9: printf("\nEnter Source and Dest Name: "); 
			char source[20],dest[20]; 
			scanf(" %s %s",source,dest); 
			execl("/bin/cp","cp",source,dest,NULL); 
			break;
		case 10:printf("\nEnter File Name: "); 
			char del[20]; 
			scanf(" %s",del); 
			execl("/bin/rm","rm",del,NULL); 
			break;
		default: printf("\nInvalid Choice."); exit(0);
	}
	return 0;
}