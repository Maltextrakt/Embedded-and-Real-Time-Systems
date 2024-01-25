// import statement for stand input putput
#include <stdio.h>
// import header file for standard library
#include <stdlib.h>
#include <ctype.h>

// main funciton that takes arguments 
int main(int argc, char *argv[]){
    // if statement that checks if no arguments are provided 
    
    if(argc == 1){
        printf("Error. Provide a number");
    // if exactly 1 argument is provided, go here
    } else if(argc==2){
        char *rawInput = argv[1];
        // declare and initialize variable that turn the input from argument[1] into int using atoi function
            int intInput = atoi(argv[1]);

        if(intInput == 0 && rawInput[0] != '0'){
            printf("Error: provide a valid number");
        }else{
            
            
            // declare variable fo type int
            int smallestType;

            // if statement that compares the argument in argv[1] with the allowed min and max for char
            if(intInput >= SCHAR_MIN && intInput <= SCHAR_MAX){
                // sets the variable smallestType to 8, in order to set the amount of bits  I wanna print
                smallestType = 8;
            // if statement that compares the argument in argv[1] with the allowed min and max for short
            } else if(intInput >= SHRT_MIN && intInput <= SHRT_MAX){
                // sets the variable smallestType to 16, in order to set the amount of bits  I wanna print
                smallestType = 16;
            // if statement that compares the argument in argv[1] with the allowed min and max for int
            } else if(intInput >= INT_MIN && intInput <= INT_MAX){
                // sets the variable smallestType to 32, in order to set the amount of bits  I wanna print
                smallestType = 32;
            // if statement that compares the argument in argv[1] with the allowed min and max for long
            } else if(intInput >= LONG_MIN && intInput <= LONG_MAX){
                // sets the variable smallestType to 64, in order to set the amount of bits  I wanna print
                smallestType = 64;
            } else {
            printf("The number you have provided is too big, provide a number of maximum size long.");
            smallestType = 0;
            }

        long int mask = 1L << (smallestType -1);

        for(int i=0; i<smallestType; i++){
            printf("%c", intInput & mask ? '1' : '0');
            mask = mask >> 1;
        }
    }
   } else {
        printf("Error: Provide only 1 argument");
   }
    

    return 0;
}