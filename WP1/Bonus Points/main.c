// header file for standard input output library, used for defining some input types, macros
// and various functions for input/output
#include <stdio.h>
// header file for standard library, used for memory allocation, process control etc
#include <stdlib.h>

// main function that takes arguments
// argc is a counter for amount of arguments in the program
// argv is an array of character pointers that lists the arguments
int main(int argc, char *argv[]){
// begin main function with if statement that checks if no user argument has been provided 
// if that is the case, quit the program gracefully     
if(argc == 1){
    // print this to console if if statement is true
    printf("Error: No number provided. Please provide a number as a command line argument.");
    // return 0 to stop the program here if the if statement is true and show that it exited successfully
    return 0;
}   
    // declare and initiallzie number variable that turns the user argument (which is a string)     
    // input into an int using the built in atoi function
    int number = atoi(argv[1]);
    // declare and initialize nOfOnes variable and set it to 0
    // this variable is used to count the amount of ones found in the binary number, skipping
    // all 0s until a 1 is found
    int nOfOnes = 0;
    // declare and initilaze nOfZeroes variable and set it to 0
    // this variable is used to count the amount of ones found in the binary number, skipping
    // all 0s until a 1 is found
    int nOfZeroes = 0;
    // create mask by utilizing left shift bitwise operator
    // shifts the number bits on the left side to the left, essentially multiplying with each operation by 2
    // this mask is commonly used in operations where you want to check individual bits of an int (32 bit)
    // mask in binary looks like this: 0b1000 0000 0000 0000 0000 0000
    int mask = 1 << 31;
    
    //if statement that checks if the numer variable (user argument) is actually a number. 
    // if it is not a number it should return something other than a 1.
    // this uses the atoi function behavior. 
    if(number <= 0){
        printf("Error: Invalid number.");
    // next part of the if statement that takes all the other cases 
    }else {
        printf("Number: %d", number);
        // prints the added "0b" to the console
        printf("\nBinary: 0b");
        //for loop that iterates over the length of the input (integer 32 bit)
        for(int i = 0; i < sizeof(number) * 8; i++){
            // if the bit in number and mask for position [i] are true (using the AND bitwise operateor), 
            // enter this part of the if statement
            // this is here in order to omit all of the 0s before the 1st one, since it wont be true until the
            // 1st 1 is encountered
            if(number & mask){
                // prints either 1 or 0 depending on if the bit in both number and mask on position [i] are 1.
                printf("%c", number & mask ? '1' : '0');
                // increment the counter for number of ones
                nOfOnes ++;
            // next part of if statement that checks if the counter for number of ones are bigger than 0
            // this is in order to ensure that no 0s are printed unless a 1 has been encoutnered first
            }else if(nOfOnes > 0){
                // same logic as in line 53
                printf("%c", number & mask ? '1' : '0');
                // incrememt counter for zeroes
                nOfZeroes ++;
            }    
            // move the binary representation of the input argument number one step to the left after each iteration
            // 0000 0001 becomes 0000 0010 for example
            number = number << 1;
        }

        // prints number of zeroes counter
        printf("\nNumber of 0s: %d\n", nOfZeroes);
        // prints number of 1s counter
        printf("Number of 1s: %d", nOfOnes);
        }
        // return 0 in order to indicate succesful exit
        return 0;
}


