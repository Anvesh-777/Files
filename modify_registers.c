#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    FILE *file;
    char buffer[100];
    

    file = fopen("registers.txt", "r+");
    if (file == NULL)
    {
        printf("Unable to open the file.\n");
        return 1;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) 
    {
        printf("Unable to create a temporary file.\n");
        fclose(file);
        return 1;
    }


    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        
        if (strstr(buffer, "Register r3") != NULL) 
	{
            fprintf(tempFile, "Register r3 Value  0x100\n");  
        }
	else 
	{
            fputs(buffer, tempFile);  
        }
    }


    fprintf(tempFile, "Register r5 Value  0x800\n");

    fclose(file);
    fclose(tempFile);


    remove("registers.txt");
    rename("temp.txt", "registers.txt");

    printf("File modified successfully.\n");

    return 0;
}

