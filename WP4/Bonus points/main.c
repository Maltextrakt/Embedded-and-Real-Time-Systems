#include <stdio.h>  // import header file standardinput output
#include <stdlib.h> // import header file standard library
#include <string.h> // import header file for string manipulation
#include <malloc.h> // import header file for memory allocation with malloc



void swap(char *x, char *y){ // swap method that takes 2 pointers, x and y, and swaps the content that they are pointing to
    char temp; // declare temporary storage variable
    temp = *x; // set temp to the content of pointer x
    *x = *y; // set the content of pointer x to content of pointer y
    *y = temp; // set the content of pointer y to temp

}

void permute(int left, int right, char *stringPtr){ // method that performs permutations, takes 3 arguments; left, right and pointer to the input string
    if(left == right){ // if statement that checks if left has reached right position
        printf("%s\n", stringPtr); 
    } else { // if left != right go here
        for(int i=left; i<=right; i++){ // iterate from left position to right, increment i 
            swap((stringPtr + left), (stringPtr + i)); // swap the character at stringptr + left with stringptr + i
            permute(left + 1, right, stringPtr); // recursive permute call that calls itself and increments left by 1 step
            swap((stringPtr + left), (stringPtr + i)); // swap back the characters again to "reset"
        }
    }

}


int main(int argc, char *argv[]){ // main method that has checks for error, and initiates the permutation

    if(argc != 2){ // check so that exactly 1 argument has been provided
        printf("invalid");
        return 0; // exit program with 0 to indicate success
    }
    int lengthOfString = strlen(argv[1]); // determine the length of the string using strlen
    

    if(lengthOfString>10){ // ensure that no more than 10 characters can be used for the string
        printf("invalid");
        return 0; // exit program with 0 to indicate success
    }

    char *inputString = (char *)malloc((lengthOfString + 1) * sizeof(char)); // declare and initailize pointer to the string using malloc to dynamically set the memory allocation, including '\0'
    strcpy(inputString, argv[1]); // copy the string from the argument and store it in the created inputString

    printf("All permutations of the string %s are:\n", inputString);
   
    permute(0, lengthOfString-1, inputString); // initialize the recursive permute mehtod

    free(inputString); // free the allocated memory to avoid memory leak

    return 0; // return 0 to indicate succesful execution.
}