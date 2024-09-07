#include<stdio.h>
#include<stdlib.h>

int main() 
{
    FILE* fp = NULL;
    int words_count = 0, character_count = 0, line_count = 0;

    fp = fopen("new_file_creation_writingdata", "r+");

    if(fp == NULL) 
    {
        printf("fopen() fails to open updated.txt file:\n");
        return 1;
    }

    int ch;
    while((ch = fgetc(fp)) != EOF)
    {
        ++character_count;
        if(ch == ' ' || ch == '\n' || ch == '\t') 
	{
            ++words_count;
        }
        if(ch == '\n')
       	{
            ++line_count;
        }
    }

    printf("Total number of words = %d\n", words_count);
    printf("Total number of characters = %d\n", character_count);
    printf("Total number of lines = %d\n", line_count);

    //fprintf(fp,"%s %d\n","Total  number of words present in this file:",words_count);
    //fprintf(fp,"%s %d\n","Total  number of characters present in this file:",character_count);
    //fprintf(fp,"%s %d\n","Total  number of lines present in this file:",line_count);

    FILE* track_fp=fopen("track_file","a+");
     if(fp==NULL)
     {
             printf("track_file open failed:\n");
             return 1;
     }
     else
     {
        fprintf(track_fp,"count_characters_words_lines_inFile.c file is exicuted at %s and %s\n",__DATE__,__TIME__);
     }

    fclose(fp);
    return 0;
}

