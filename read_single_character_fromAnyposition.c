#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *fp = NULL;
    int ch, position, i = 0;

    // Ask the user for the character position they want
    printf("Enter the character position you want to read: ");
    scanf("%d", &position);

    // Open the file in read mode
    fp = fopen("new_file_creation_writingdata", "r");

    // Check if the file was opened successfully
    if (fp == NULL)
    {
        printf("The file you want is not found\n");
        return 0;
    }

    // Read up to the desired position
    while (i < position)
    {
        ch = fgetc(fp);
        if (ch == EOF)
       	{
            printf("Reached end of file before the specified position.\n");
            fclose(fp);
            return 0;
        }
        i++;
    }

    // Use ternary operator to print the result
    ch != EOF ? printf("The character at position %d is %c\n", position, ch) : printf("File is empty\n");

     FILE* track_fp=fopen("track_file","a+");
     if(fp==NULL)
     {
	     printf("track_file open failed:\n");
	     return 1;
     }
     else
     {
        fprintf(track_fp,"read_single_character_fromAnyposition.c file is exicuted at %s and %s\n",__DATE__,__TIME__);
     }

    // Close the file
    fclose(fp);

    return 0;
}

