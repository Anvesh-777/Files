#include <stdio.h>
#include <stdlib.h>

int main() {
    // File pointers
    FILE* fp;
    FILE* fp1;
    // Buffer to store the read data
    char *buffer = NULL;
    // Variable for file length
    long len = 0;

    fp = fopen("new_file_creation_writingdata", "r");

    // Check if file opening is successful
    if (fp == NULL) 
    {
        printf("fopen() function fails:\n");
        exit(1);
    }

    // Get the length of the file
    fseek(fp, 0, SEEK_END);
    len = ftell(fp);
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

    // Close the source file
    fclose(fp);

    // Open the target file in write mode
    fp1 = fopen("Data_written_from_another_file", "w");

    // Check if file opening is successful
    if (fp1 == NULL) 
    {
        printf("fopen() function fails:\n");
        exit(1);
    }

    // Write the buffer to the target file
    fwrite(buffer, sizeof(char), len, fp1);

    // Close the target file
    fclose(fp1);

    // Free dynamically allocated memory
    free(buffer);

    // Open the tracking file in append mode
    FILE* track_fp = fopen("track_file", "a+");
    if(track_fp == NULL)
    {
        printf("track_file open failed:\n");
        return 1;
    }
    else
    {
     fprintf(track_fp, "read_write_file_content_inAnotherFile_by_using_fread.c file is executed at %s and %s\n", __DATE__, __TIME__);
    }

    // Close the tracking file
    fclose(track_fp);
    return 0;
}

