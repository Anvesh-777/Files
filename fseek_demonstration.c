#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = NULL;
    fp = fopen("new_file_creation_writingdata", "r");

    if (fp == NULL)
    {
        printf("fopen() function fails:\n");
        exit(1);
    }

   // fseek(fp, 2, SEEK_CUR);
    fseek(fp,5, SEEK_SET);
   //fseek(fp, 0, SEEK_END);
    int character = fgetc(fp);

    if (character != EOF)
    {
        printf("Character at current cursor position: %c\n", (char)character);
    }
    else
    {
        printf("End of file reached.\n");
    }
    
    FILE* track_fp=fopen("track_file","a+");
     if(track_fp==NULL)
     {
             printf("track_file open failed:\n");
             return 1;
     }
     else
     {
        fprintf(track_fp,"fseek_demonstration.c file is exicuted at %s and %s\n",__DATE__,__TIME__);
     }

    fclose(track_fp);
    fclose(fp);
    return 0;
}


