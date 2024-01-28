// import heade file standard input output 
#include <stdio.h>
// import header file standard library
#include <stdlib.h>
// import unistd in order to utilize isatty function
#include <unistd.h>

// main function that turn binary numbers into hexadecimal depending on if it is being called via pipe
// or by itself
// can take arguments, or not, depending on usage
int main(int argc, char *argv[]){

    // declare variable character
    int character;

    // if statement that checks if the content in stdio comes from the command line or from another program
    // utilizes isatty function
    // if content in stdio is not from command line, go here
    if(!isatty(STDIN_FILENO)){
        // declare and initialize variable index, set to 0.
        int index = 0;
        // declare variable of type character array of size 100
        char binaryInput[100]; 
        
        // while loop that runs while the current character is not an end of file character and not a newline
        // character and index is less than 99
        while((character = getchar()) != EOF && character != '\n' && index<99){
            // if statement that checks if the current character from getchar() is 1 or 0, ensuring
            // that the input is actually a binary number
            if(character == '1' || character == '0'){
                // copy the current character to binaryInput and increment index counter
                binaryInput[index++] = character;    
            // else statement that goes here if the input is not 1 or 0
            } else{
                // break the while loop if this is the case
                fprintf(stderr, "Error: Non-binary character detected in input.\n");
                return 1;
            }
        }
        // set the null character at the end of the character array ("string")
        // indicates the end of the array
        binaryInput[index] = '\0';
        // declare and initialize variable that takes binaryInput variable and turns it to a long
        // turn to long (int ) in order to be able to print it with "%x"
        // number 2 because binary
        int binaryInputValue = strtol(binaryInput, NULL, 2);
        printf("%X\n", binaryInputValue);
    // next part of the if statement that checks if an argument has been provided in the command line
    } else if (argc == 2){
        // declare and initialize pointer that points to the content of the argument in position 1,
        // provided by the user
        char *binaryInputArgument = argv[1];
        // declare and initialize variable that takes the content from what *binaryInputArgument points to
        // and turns it into long
        int binaryInputValue = strtol(binaryInputArgument, NULL, 2);
        printf("%X\n", binaryInputValue);
    // else statement that covers all other cases, i.e. if no argument or more than 1 argument is being provided.
    } else {
        printf("Error. Provide exactly 1 argument.");
        // return 1 to indicate error.
        return 1;
    }
    // return 0 to indicate success
    return 0;
}