#include <stdio.h>
#include <stdlib.h>

int main() {
    // File pointer
    FILE* fp;
    // Buffer to store the read data
    char *buffer = NULL;
    // Variable for file length
    long len = 0;

    fp = fopen("new_file_creation_writingdata", "r");

    // Check if file opening is successful
    if (fp == NULL) {
        printf("fopen() function fails:\n");
        exit(1);
    }

    // Get file length
    fseek(fp, 0, SEEK_END);
    len = ftell(fp);
    rewind(fp);

    // Allocate buffer of file length
    buffer = (char*)malloc((len + 1) * sizeof(char));
    if (buffer == NULL) {
        printf("Memory allocation failed.\n");
        fclose(fp);
        exit(1);
    }

    // Read the file character by character and store in buffer
    int ch;
    int i = 0;
    while ((ch = fgetc(fp)) != EOF) {
        buffer[i] = (char)ch;
        i++;
    }

    // Null-terminate the buffer
    buffer[len] = '\0';

    // Print the read data
    printf("%s", buffer);

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
        fprintf(track_fp,"read_file_content_by_Without_using_fread.c file is exicuted at %s and %s\n",__DATE__,__TIME__);
     }

    // Close the file
    fclose(track_fp);
    fclose(fp);
    return 0;
}

