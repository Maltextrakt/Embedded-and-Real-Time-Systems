// import statement for stand input putput
#include <stdio.h>
// import header file for standard library
#include <stdlib.h>
// import header file for string manipulation functionality such as strcmp
#include <string.h>

// main funciton that takes arguments 
int main(int argc, char *argv[]){
    // if statement that checks if no arguments are provided 
    if(argc == 1){
        printf("Error. Provide a number");
    // if exactly 1 argument is provided, go here
    } else if(argc==2){

        // variable pointer declaration that points to char. initialized to the argument in position [1]
        char *rawInput = argv[1];

        // if statement that checks if the input from argv[1] is -h
        // if they are equal it returns 0 and this check is thus true
        if(strcmp(rawInput, "-h") == 0){
            printf("Instructions: Provide a positive integer. Do not provide more than one number at at time.");
            // return 0 to indicate succesful exit
            return 0;
        }
        // declare and initialize variable that turn the input from argument[1] into int using atoi function
        int intInput = atoi(argv[1]);

        //if statement that checks if the variable intinput is 0 and rawInput character on
        // position 0 is not equal to 0
        // this ensures that if you enter the number 0 it accepts it as a valid number using atoi
        // atoi returns 0 if it is not able to convert it to integer, in this case the rawInput[0] != '0' 
        // will be true and thus return an error
        if(intInput == 0 && rawInput[0] != '0'){
            printf("Error: provide a valid number. Enter -h for more information.");
            return 2;
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
        printf("Error: Provide only 1 argument. Call file with -h for more information");
        return 2;
   }
    

    return 0;
}