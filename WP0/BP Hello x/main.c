// import standard input/output library header file
#include <stdio.h>
// import string library header file
// used for manipulating strings in varios ways, "strlen" for example
#include <string.h>

// main function where argc and argv are used for command line processing
// argc is the counter for arguments in the program
// argv is an array of character pointers that lists the arguments
int main(int argc, char *argv[]){
    //if statement that checks if the argument pointers in position [1] are null
    // if not null, it skips this if statement
    if(argv[1] == NULL){
        //prints this message if the argument pointers in position [1] are null
        printf("No command line argument provided, please provide a name.");
    // next step of the if statement
    // program excutes this everytime that the if statement above is false
    } else {
        // if statement that compares the length of the argument pointers on position [1] with the int 50
        // if argv[1] is greate or equal to 50 execute this statement
        if(strlen(argv[1])>50){
            // print this message if the argv[1] is greater than 50
            printf("Name too long, max 50 characters");
        // next step of the if statement
        // checks if the length of the argument pointers on position [1] are shorter than 3
        } else if(strlen(argv[1])<3){
            // print this message if the strlen(argv[1]<3 is true)
            printf("Name too short, min 3 characters");
        // next step of the if statement
        // execute this section of the statement in all other cases other than the 2 cases checked in 
        // the first 2 checks above
        // i.e. if the length of the argument pointers is between 3 and 50
        } else {
            // print statement that takes the input from the command line 
            printf("Hello " "%s",argv[1]);
            // second part of the print statement that prints it right after the one above
            printf(", how is your day today?");
        }
    }
    // return 0 at the end of the method as a way for the system to indicate successful exit.

    return 0;
}