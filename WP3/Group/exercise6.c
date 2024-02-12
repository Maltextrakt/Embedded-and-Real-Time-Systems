#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX 20

char inputString[MAX + 1];  //declare string (array of characters), do MAX+1 to include the null terminator

void copyString(char *destinationToSaveString, char *stringToCopy){
    int sizeOfString = strlen(stringToCopy);

    for(int i=0; i<sizeOfString; i++){
        destinationToSaveString[i] = stringToCopy[i];
    }

    destinationToSaveString[sizeOfString] = '\0';   // add null terminator character to determine end of string at end of string

}

int main(int argc, char *argv[]){

    printf("Enter a string of maximum 20 characters: \n");
    scanf("%19s", inputString);

    char *ptr = inputString;

    while(*ptr != '\0'){
        printf("%c", *ptr);
        ptr++;
    }
    printf("\n");

    /*    char copiedString[MAX +1];        // print using library strcpy function
    strcpy(copiedString, inputString);
    printf("Copied string: %s", copiedString);*/

    char copiedString[MAX +1];
    copyString(copiedString, inputString);
    printf("Copied string: %s\n", copiedString);



    return 0;
}