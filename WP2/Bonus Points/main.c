// import header file std input output
#include <stdio.h>
// import header file for string manipulation
#include <string.h>
// import header file for using sleep (unix version)
#include <unistd.h>
// import hedaer file for standard library in c
#include <stdlib.h>

// enum for days which ends in a day which is outside the size of the week (endOfEnumDay)
enum Day{Mon = 1, Tue, Wed, Thu, Fri, Sat, Sun, endOfEnumDay};
// enum for week days, ending in endOfEnumWeek
enum Week{Week1 = 1, Week2, Week3, Week4, Week5, endOfEnumWeek};


// switch case that takes days from our earlier enum Day
// switch case because we are not alloweed to store in strings/arrays
const char* fullDayName(enum Day day) {
    // declare the different switch cases that takes days
    switch(day) {
        // monday, if case Mon is detected it return the full name of the day
        case Mon: return "Monday";
        // tuesday, if case Tue is detected it return the full name of the day
        case Tue: return "Tuesday";
        // wedensday, if case Wed is detected it return the full name of the day
        case Wed: return "Wednesday";
        // Thursday, if case Thu is detected it return the full name of the day
        case Thu: return "Thursday";
        // Friday, if case Fri is detected it return the full name of the day
        case Fri: return "Friday";
        // Saturday, if case Sat is detected it return the full name of the day
        case Sat: return "Saturday";
        // Sunday, if case Sun is detected it return the full name of the day
        case Sun: return "Sunday";
        // default case, this is printed if the switch case is something other than the above
        default: return "invalid";
    }
}

// main function that takes inputs from console, removes \n from them and then prints the corresponding
// week and day, depending on the input, with 1 second delay between each print
int main(int argc, char *argv[]){
    // declare buffer that is used to store input from user, size 10
    char inputBuffer[10];
    // variable that takes user input for week, type int
    int inputWeek;
    // variable that takes user input fr day, type int
    int inputDay;
    
    // fgets to read user input
    fgets(inputBuffer, sizeof(inputBuffer), stdin);
    // variable that determines lenth of user input stored in stdin
    int len = strlen(inputBuffer);
    // if statement that chcks if the length of input is greater than 0 and inputbuffer content on next to
    // last posiiton is '\n'
    if(len > 0 && inputBuffer[len - 1] == '\n') { 
        // if the above is true then set that position content to '\0'
        inputBuffer[len - 1] = '\0';
        // decrement len to decrease length of string stored in buffer after removing newline character
        len--;
    }
    // Parse an integer from inputBuffer into inputWeek and check if inputBuffer ends with "\\n"
    if(sscanf(inputBuffer, "%d", &inputWeek) == 1 && strcmp(inputBuffer + strlen(inputBuffer) - 2, "\\n") == 0) {
    // in all other cases do this
    } else {
        // prints invalid week to console
        puts("invalid week");
        // return 0 to indicate succes
        return 0;
    }

    // read a line of input from the user and store it in inputBuffer
    fgets(inputBuffer, sizeof(inputBuffer), stdin);
    // see if inputBuffer has a newline character at the end
    if(len > 0 && inputBuffer[len - 1] == '\n') { 
        // content on next to last position is set to \0
        inputBuffer[len - 1] = '\0';
        // decrement len
        len--;
    }

    //parse an integer from inputBuffer into inputDay and check if inputBuffer ends with "\\n"
    if(sscanf(inputBuffer, "%d", &inputDay) == 1 && strcmp(inputBuffer + strlen(inputBuffer) - 2, "\\n") == 0) {
    // in all other cases go here
    } else {
        // print invalid day
        puts("invalid day");
        // return 0 to indicate sucdss
        return 0;
    }
   
    // check to ensure valid input by user, minimum week 1, max week 5
     if(inputWeek<Week1 || inputWeek > Week5){
        printf("invalid week\n");
        // return 0 to indicate sueccess
        return 0;
    }
    // check to ensure valid input by user for day, min Mon (1), max Sun(7)
    if(inputDay < Mon || inputDay > Sun){
        printf("invalid day\n");
        // return 0 to indicate successful execution
        return 0;
    }


    // for loop that iterates over the week input by the user and up to maximum 5
    for(; inputWeek <= Week5; inputDay++) {
        // if statement that checks if input day is bigger than sinday
        if(inputDay > Sun) {
            // if so, set the day to Mon (reset the week)
            inputDay = Mon;
            // increment the week
            inputWeek++;
            // break the loop if the week input is greate than 5
            if(inputWeek > Week5) break; 
        }
        // print the name if the current week, and fulldayname using the enums
        printf("Week %d, %s\n", inputWeek, fullDayName((enum Day)inputDay));
        // ensure that the print is immediately displayed on the screen
        fflush(stdout);
        // delay by 1 second using the unistd library
        sleep(1);

    }   
    // return 0 to indicate success
    return 0;
}
    

