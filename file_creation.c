#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp=NULL;
	fp=fopen("/home/anvesh/FILES/new_file_creation_by_code","w+");
	if(fp==NULL)
	{
		printf("fopen() function failed:\n");
		exit(0);
	}
	printf("New file creatoin successfully completed.\n");
	FILE* track_fp=fopen("track_file","a+");
	fprintf(track_fp,"file_creation.c file is exicuted at %s and %s\n",__DATE__,__TIME__);
	
	fclose(track_fp);
	fclose(fp);
	return 0;
}
