#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "fileio.h"

int demoOpenClose(const char * fileName, const char * fileMode)
{
    //Pointer to a file stream
    FILE * filePtr;

    //A variable to store potential error codes
    int iErr = EXIT_SUCCESS;

    //use fopen to open a file. note that it returns a FILE pointer that must be
    //assigned. If it fails, it returns a NULL and sets the errno variable to
    //indicate an error. Parameters are a const char * indicating a
    //path/filename. The second is a const char * indicating the mode (read,
    //write, append, ect). See document on handout drive.

    if((filePtr =  fopen(fileName, fileMode)) != NULL )
    {
        //close the file when done
        fclose(filePtr);
        printf("%s was successfully opened and closed.\n", fileName);
    }
    else
    {
        iErr = errno;
        printf("Error accessing the file %s: %s\n", fileName, strerror(iErr));
    }
    return iErr;
}

int demoRead(const char * fileName, const char * fileMode)
{
    FILE * filePtr;
    int iErr = EXIT_SUCCESS;
    int intChar, retVal;
    char cBuffer [MAXSIZE];

    //all read operations read data from the file to t he memory location
    //indicated (cBuffer). Only fgets adds an additional nul terminator to the
    //data in the buffer. Return types vary, so testing for success depends on
    //the function used
    //fscanf/fread - return number of times assigned/read, fscanf returns EOF if
    //a failure occurs
    //fgets - returns a pointer tot he string read or NULL
    //fgetc - returns the character or EOF

    if((filePtr =  fopen(fileName, fileMode)) != NULL )
    {
        //how to initialize a buffer
        memset(cBuffer, '\0', MAXSIZE);

        retVal = fscanf(filePtr, "%s\n", cBuffer); //Quits at a space
        if(retVal > 0)
        {
            printf("%s\n", cBuffer);    
        }
        else
        {
            if(iErr = ferror(filePtr))
            {
                    printf("Error reading from the file %s: %s\n", fileName,
                    strerror(iErr));
            }
            else
            {
                printf("Could not retrieve data.\n");    
            }
        }

        //close the file when done
        fclose(filePtr);
        printf("%s was successfully opened and closed.\n", fileName);
    }
    else
    {
        printf("Error accessing the file %s: %s\n", fileName, strerror(iErr));
    }
    return iErr;

}

int demoWrite(const char * fileName, const char * fileMode, const char * str)
{
    FILE * filePtr;
    int iErr = EXIT_SUCCESS;
    int intChar, retVal;
    char cBuffer [MAXSIZE];

    if((filePtr =  fopen(fileName, fileMode)) != NULL )
    {
        retVal = fwrite((void *)str, sizeof(char), strlen(str), filePtr);
        if(retVal > 0)
        {
            printf("File writen: %s\n", fileName);    
        }
        else
        {
            if(iErr = ferror(filePtr))
            {
                    printf("Error writing to the file %s: %s\n", fileName,
                    strerror(iErr));
            }
            else
            {
                printf("Could not write data.\n");    
            }
        }

        //close the file when done
        fclose(filePtr);
        printf("%s was successfully wrote tot he file.\n", fileName);
    }
    else
    {
        printf("Error accessing the file %s: %s\n", fileName, strerror(iErr));
    }
    return iErr;
}

int demoWriteBinary(const char * fileName, const char * fileMode, const int * iPtr)
{
    FILE * filePtr;
    int iErr = EXIT_SUCCESS;
    int intChar, retVal;

    if((filePtr =  fopen(fileName, fileMode)) != NULL )
    {
        retVal = fwrite((void *)iPtr, sizeof(int), 1, filePtr);
        if(retVal > 0)
        {
            printf("File writen: %s\n", fileName);    
        }
        else
        {
            if(iErr = ferror(filePtr))
            {
                    printf("Error writing to the file %s: %s\n", fileName,
                    strerror(iErr));
            }
            else
            {
                printf("Could not write data.\n");    
            }
        }

        //close the file when done
        fclose(filePtr);
        printf("%s was successfully wrote tot he file.\n", fileName);
    }
    else
    {
        printf("Error accessing the file %s: %s\n", fileName, strerror(iErr));
    }
    return iErr;
}

int exerciseBinaryWrite(const char* fileName, const char * fileMode)
{
    FILE * filePtr;
    int iErr = EXIT_SUCCESS;
    int intChar, retVal;
    
    if((filePtr =  fopen(fileName, fileMode)) != NULL )
    {
	    short x = 0;
    	printf("\nHow many records?\n");
    	scanf("%hu", (short *)&x);
    	retVal = fwrite((void *)&x, sizeof(short), 1, filePtr);    

    	while(x)
    	{
            int sn = 0;
            printf("\nsin number:\n");
            scanf("%d", (int *)&sn);
            retVal = fwrite((void *)&sn, sizeof(int), 1, filePtr);

            char cName[MAXNAME];
            printf("\nYour name:\n");
            scanf("%20s", cName);
            retVal = fwrite((void *)&sn, sizeof(int), 1, filePtr);
            x--;
    	}	

        if(retVal > 0)
        {
            printf("File writen: %s\n", fileName);    
        }
        else
        {
            if(iErr = ferror(filePtr))
            {
                    printf("Error writing to the file %s: %s\n", fileName,
                    strerror(iErr));
            }
            else
            {
                printf("Could not write data.\n");    
            }
        }

        //close the file when done
        fclose(filePtr);
        printf("%s was successfully wrote tot he file.\n", fileName);
    }
    else
    {
        printf("Error accessing the file %s: %s\n", fileName, strerror(iErr));
    }
    return iErr;

}

int exerciseBinaryRead(const char* fileName, const char * fileMode, int id)
{
        
}
