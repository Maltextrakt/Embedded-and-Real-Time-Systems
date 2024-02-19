#include <stdio.h>  // import header file standardinput output
#include <stdlib.h> // import header file standard library
#include <string.h> // import header file for string manipulation
#include <malloc.h> // import header file for memory allocation with malloc


int factorial(int n){ // method that calculates the factorial of an integer argument
    if (n==0) return 1; // if the argument is zero return 1 
    int result = 1; // declare and initialize variable to 1
    for(int i=1; i<=n; ++i){ // iterate over the size of n, starting with i = 1
        result = result * i; // multiply result with i
    
    }
    return result; // return the factorial result
}


void swap(char *x, char *y){ // swap method that takes 2 pointers, x and y, and swaps the content that they are pointing to
    char temp; // declare temporary storage variable
    temp = *x; // set temp to the content of pointer x
    *x = *y; // set the content of pointer x to content of pointer y
    *y = temp; // set the content of pointer y to temp

}

void permute(char **permutations, int left, int right, char *stringPtr, int *permCount){ // method that performs permutations, takes 5 arguments; left, right and pointer to the input string, counter for number of permutations and double pointer to the permutations
    if(left == right){ // if statement that checks if left has reached right position
        strcpy(permutations[(*permCount)++], stringPtr); // copy current permutation string pointed to by stringPtr, into the array pointed to by permCount, then increment count so that next string is stored in the next index
    } else { // if left != right go here
        for(int i=left; i<=right; i++){ // iterate from left position to right, increment i 
            swap((stringPtr + left), (stringPtr + i)); // swap the character at stringptr + left with stringptr + i
            permute(permutations, left + 1, right, stringPtr, permCount); // recursive permute call that calls itself and increments left by 1 step
            swap((stringPtr + left), (stringPtr + i)); // swap back the characters again to "reset"
        }
    }

}


int main(int argc, char *argv[]){ // main method that has checks for error, and initiates the permutation

    if(argc != 2){ // check so that exactly 1 argument has been provided
        printf("invalid");
        return 0; // exit program with 0 to indicate success
    }
    char *inputString = argv[1]; // set inputString to the address for argument provided when calling the program
    int lengthOfString = strlen(argv[1]); // determine the length of the string using strlen
    int numOfPermutations = factorial(lengthOfString); // count number of total permutations, later used to allocate memory dynamically
    
    if(lengthOfString>10){ // ensure that no more than 10 characters can be used for the string
        printf("invalid");
        return 0; // exit program with 0 to indicate success
    }

    char **permutations = malloc(numOfPermutations * sizeof(char *)); // dynamicaly allocate memory for the size of the "2d array"
    for(int i=0; i<numOfPermutations; ++i){ // iterate over the 2d array 
        permutations[i] = malloc((lengthOfString + 1) * sizeof(char)); // for each index in the 2d array, allocate memory according to the size of the string in bits (plus the end of line character)
    }
   
    int permutationCount = 0; // initialize counter for permutations to 0
    permute(permutations, 0, lengthOfString-1, inputString, &permutationCount); // initialize the recursive permute mehtod
    printf("All permutations of the string %s are:\n", inputString);
    for(int i=0; i<permutationCount; ++i){ // iterate over the number of permutations
        printf("%s\n", permutations[i]); // print each permutation using index i
    }

    for(int i=0; i<numOfPermutations; ++i){ // iterate over the number of permutations in the 2d array
        free(permutations[i]); // free the allocated memory for each permutation to avoid memory leak
    }
    free(permutations); // free the allocated memory for the whole 2d array to avoid memory leak

    return 0; // return 0 to indicate succesful execution.
}