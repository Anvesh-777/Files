#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *source_file = NULL, *destinuation_file=NULL;
    int var=0;
    
    source_file = fopen("new_file_creation_writingdata", "r+");

    if (source_file == NULL) 
    {
        printf("fopen() function fails:\n");
        return 1;
    }

 
    destination_file=fopen("Case_Converted.txt","w");

    if(destination_file==NULL)
    {
	    printf("fopen fails:\n");
	    return 1;
    }

    while ((var = fgetc(source_file)) != EOF)
    {
        if ((var >= 'a') && (var <= 'z')) 
	{
            var = var - 32; // Convert lowercase to uppercase
        }
       	else if ((var >= 'A') && (var <= 'Z')) 
	{
            var = var + 32; // Convert uppercase to lowercase
        }
        fputc(var,destination_file);
    }

     FILE* track_fp=fopen("track_file","a+");
     if(track_fp==NULL)
     {
             printf("track_file open failed:\n");
             return 1;
     }
     else
     {
        fprintf(track_fp,"case_conversion_of_file_content.c file is exicuted at %s and %s\n",__DATE__,__TIME__);
     }

    fclose(track_fp);
    fclose(source_file);
    fclose(destination_file);
    return 0;
}


