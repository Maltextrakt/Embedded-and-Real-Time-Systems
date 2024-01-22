// imports the stdio library which defines some input types, macros and various functions for I/O
#include <stdio.h>

// main function where argc and argv are used for command line argument processing
// argc (argument count) = number of command line arguments passed to the program
// argv (argument vector) = array of character pointers that lists all arguments

int main(int argc, char *argv[]){

    // prints out "hello world" to the console
    printf("hello world");

    // return 0 in order for the system to indicate the exit status of the system
    // exit status 0 tells the OS that it executed successfully 
    return 0;
}