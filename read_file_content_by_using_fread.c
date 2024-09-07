#include <stdio.h>
#include <stdlib.h>

int main() {
    // File pointer
    FILE* fp;
    // Buffer to store the read data
    char *buffer = NULL;

    
    fp = fopen("new_file_creation_writingdata", "r");

    // Check if file opening is successful
    if (fp == NULL) 
    {
        printf("fopen() function fails:\n");
        exit(1);
    }

    // Get the length of the file
    fseek(fp, 0, SEEK_END);
    long len = ftell(fp);
    rewind(fp);

    // Allocate memory for buffer
    buffer = (char*)malloc((len + 1) * sizeof(char));
    if (buffer == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Read the file into the buffer
    fread(buffer, sizeof(char), len, fp);
    // Add null terminator at the end
    buffer[len] = '\0';

    // Print the read data
    printf("The file data is\n%s", buffer);

    // Free dynamically allocated memory
    free(buffer);
	
    FILE* track_fp=fopen("track_file","a+");
     if(fp==NULL)
     {
             printf("track_file open failed:\n");
             return 1;
     }
     else
     {
        fprintf(track_fp,"read_file_content_by_using_fread.c file is exicuted at %s and %s\n",__DATE__,__TIME__);
     }
    // Close the file
     fclose(track_fp);
     fclose(fp);
    return 0;
}


