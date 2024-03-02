#include <stdio.h> // import header file standard input output
#include <stdlib.h> // import header file standard library
#include <string.h> // import header file for manipulating strings, such as strcpy

char strings[5][1000]; // declare 2d array strings of size 5*1000

void findShortestAndRemove(char strings[5][1000]){ // helper method that find the shortest string and removes it by moving each string one step, and setting the content of the removed string to only "\0" 
    int shortestInd = 0; // declare and initialize int that keeps track of what index the shortest string is at
    int shortestLength = strlen(strings[0]); // declare and initailize variable that keeps track of the shortest length string, set it to position 0 to begin with
    int size = 5; // declare and initialize variable size, set to 5, 5 is the minimum && maximum number of strings for this prgram

    for(int i=0; i<size; i++){ // iterate over the number of strings (5)
        int currentLength = strlen(strings[i]); // declare and initailize variable that keeps track of the currentlength of the current string 
        if(currentLength < shortestLength){ // compare the size of the current string and the shortest string, if current is shorter than shortest..
            shortestLength = currentLength; // update the shortest string to the current one
            shortestInd = i; // set the corresponding index for the shortest string
        }
    }

    printf("Shortest string removed: %s", strings[shortestInd]); 

    for(int i=shortestInd; i<size-1; i++){ // iterate from shortest index to the size-1(because were using i+1 below, would get undefined behavior otherwise), and moving each coming string one step to the left, replacing the one before
        strcpy(strings[i], strings[i+1]); // copy the content from the string to the "right" into the left, rpelacing the string before
    }

    strings[size - 1][0] = '\0'; // set the last string of the 2d array to empty, thus making it an empty string

}
int main(int argc, char *argv[]){ // main function that scans input from stdin and stores each string in strings array, then prints out the removed string and the array of strings after removing shortest
    int i; // declare variable i of type int

    for(i=0; i<5; i++){       // iterate over the size of the amount of strings (5)  
        fgets(strings[i], 1000, stdin); // scan the strings, 1 at a time until end of line is encountered
        strings[i][strcspn(strings[i], "\n")] = '\0'; // remove the newline character from each string, ensuring correct reading of it
    }

    findShortestAndRemove(strings); // method call that finds and removes shortest string from strings

    printf("\nArray after removal:\n"); 
    for(i=0; i<4; i++){ // iterate over the 2d array, where we are only interested in 4 out of 5 strings now, since the shortest is removed
        if(strings[i][0] != '\0'){ // if the string on index i does not start with end of line character..
            printf("%s\n", strings[i]); // print the string
        }
    }

    return 0; // return 0 to indicate successful execution
}