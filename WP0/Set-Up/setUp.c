// (C) Malte, Kalle, Isaac, group: 20 (2024)
// Work package 0
// Exercise 1
// Submission code: XXXXXX (provided by your TA-s)

// include statements, tells the preprocessor what to include as part of what to compile

// stdio.h, standard input output header file
#include <stdio.h>
// import string library header file
// used for manipulating strings in various ways, such as strcmp
#include <string.h>


// Main function in the program, 
// argc is the counter for arguments in the program
// argv is an array of character pointers that lists the arguments
int main (int argc, char *argv[]) {

// if statement that checks if the argument on position 1 (first argument provided by user) is null
if(argv[1] == NULL){
    //prints a message to the console if the above if check is true
    printf("Error, no argument provided. Type ""-h"" for more information");
// next if statement check that checks if the argument on position 2 is not null (it exists)
} else if(argc > 2){
    // prints a mesage to the console if argument [2] is not null
    printf("Do not enter more than 1 argument! Type ""-h"" for more information");
// next if statement check that compares the argument on position 1 with "-h" using strcmp method
} else if(strcmp(argv[1], "-h") == 0){
    // prints a message to the console if the argument [1] is "-h"
    printf("You have to provide 1 argument, not less and not more!");
// final part of the if statement check, execute this part of the code for all events that are not caught in
// any of the above checks
} else {
    // Print a string to the console with the argument content on position [1]
    printf("Hello World! - I'm " "%s", argv[1]); // Note: double quotes
} 
// return 0 as a way for the system to indicate successful execution
return 0;
}