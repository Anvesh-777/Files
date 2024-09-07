#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE* fp=NULL;
	fp=fopen("new_file_creation_writingdata","a+");
	
	if(fp==NULL)
	{
		printf("fopen function failed:\n");
		return 1;
	}
	printf("New file created successfully:\n");
	fprintf(fp,"%s","The path to success is rarely a straight line.\nIt is filled with detours, roadblocks, and challenges.\nEvery rejection is a redirection, every failure a lesson.\nIn the struggle, we find strength, and in persistence, we find victory.\nKeep moving forward, for the destination is worth the journey.\n");
	printf("Data writing completed successfully:\n");
	
	 FILE* track_fp=fopen("track_file","a+");
        fprintf(track_fp,"file_creation_writingdata.c file is exicuted at %s and %s\n",__DATE__,__TIME__);

        fclose(track_fp);
	fclose(fp);
	return 0;	
}
