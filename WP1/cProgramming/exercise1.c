// header import for standard input output librar
#include <stdio.h>

// main function that prints different sentences to console depending on what number is being entered.
int main(int argc, char *argv[]){

    // declare and initialize a set of characters set to max size 25 
    char a[25] = "You entered number 1\n";
    // declare and initialize a set of characters set to max size 25 
    char b[25] = "You entered number 2\n";
    // declare and initialize a set of characters set to max size 25 
    char c[25] = "You entered number 3\n";
    // declare and initialize a set of characters set to max size 25 
    char d[25] = "You entered number 4\n";
    // declare and initialize a set of characters set to max size 25 
    char e[25] = "You entered number 5\n";

    // declare variable input of type int
    int input;
    
    // do while loope that prints continuosuly depending on what the user inputs in the console
    do {

        printf("Please enter a number between 1 and 5: ");
        //scans what the user inputs and puts it into location of variabl input
        scanf("%d", &input);

        // if statement, go here if input is 1
        if(input == 1){
            printf(a);
        // if statement, go here if input is 2
        } else if(input == 2){
            printf(b);
        // if statement, go here if input is 3
        } else if(input == 3){
            printf(c);
        // if statement, go here if input is 4
        } else if(input == 4){
            printf(d);
        // if statement, go here if input is 5
        } else if(input == 5){
            printf(e);
        }
    // condition for the do while loop that checks if input is between 0 and 6
    } while (input >0 && input <6);
    //return 0 to indicate successful execution
    return 0;
}