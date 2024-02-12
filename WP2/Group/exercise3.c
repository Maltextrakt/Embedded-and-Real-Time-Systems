// (C)_Isaac Lindegren Ternbom, Karl Eriksson, Malte Bengtsson, group 20 (2024)
// Work package 2
// Exercise 3
// Submission code: 202020


// import header file standard library
#include <stdlib.h>
// import header file standard input output
#include <stdio.h>
// import header file for string manipulation
#include <string.h>


// -----typedefs -------
typedef struct {            // declare struct of type typedef
    char firstname[20];       // first part of struct, firstname character of size 20
    char famname[20];           // 2nd part of struct, firstname of type character size 20
    char pers_number[13]; // yyyymmddnnnc, 3rd content of struct, person number of type character size 13
} PERSON;               // struct name PERSON

// Function declaration (to be extend)
PERSON input_record(void){      // method of type PERSON that doesnt take arguments that stores temporary person info
    PERSON temp;            // declare variable temp of type PERSON

    printf("Input first name for person: "); 
    scanf("%19s", temp.firstname);      // scan for firstname

    printf("Input family name for person: ");
    scanf("%19s", temp.famname);        // scan for family name

    printf("Input personal number for person (yyyymmddnnnnc): ");
    scanf("%12s", temp.pers_number);       // scan for person number

    return temp;        // return the temporary PERSON data
}          
// Reads a person’s record.
void write_new_file(PERSON *inrecord){  // method that creates a new file and overwrites the current one if it exists
    FILE *file = fopen("database.bin", "wb");   // create new pointer to file and open it, name of file is database.bin, using writebinary
    if(file == NULL){       //check if previous file exists and can be opened, if not it print error message and exit
        printf("Error opening file.\n");
        exit(1);    // terminate the program with exit status 1
    }
    fwrite(inrecord, sizeof(PERSON), 1, file);  // write PERSON record to the file
    fclose(file);           // close the file after use
}         

void printfile(void){       // Prints out all persons in the file

    FILE *file = fopen("database.bin", "rb");       // create new pointer of type FILE that opens database.bin in readbinary mode 
    if(file == NULL){       //check if previous file exists and can be opened, if not it print error message and exit
        printf("Error opening file, file does not exist");
        exit(1);        // terminate the program with exit status 1
    }
    PERSON temp;        // declare variable temp of type PERSON
    while(fread(&temp, sizeof(PERSON), 1, file)){       // while there are contents to read inside file until the end of the file
        printf("%s %s %s \n", temp.firstname, temp.famname, temp.pers_number);
    }
    fclose(file);   // close the file after use
}         

void search_by_firstname(char *name){               // Prints out the person if in list
    FILE *file = fopen("database.bin", "rb");       // create new pointer of type FILE that opens database.bin in readbinary mode
    if(file == NULL){           //check if previous file exists and can be opened, if not it print error message and exit
        printf("Error opening file, file does not exist");
        exit(1);            // terminate the program with exit status 1
    }
    PERSON temp;    // declare variable temp of type PERSON
    while(fread(&temp, sizeof(PERSON), 1, file)){      // while there are contents to read inside file until the end of the file
        if (strcmp(temp.firstname, name) ==0 || strcmp(temp.famname, name) == 0){   // if check that compares input name with firstnames OR lastnames to serach for
            printf("Found persons: %s %s %s\n", temp.firstname, temp.famname, temp.pers_number);
        }
    }
    fclose(file);   // close the file after us
}     

void append_file(PERSON *inrecord){     // method to append new file to the document file
    FILE *file = fopen("database.bin", "ab");       // create new pointer of type FILE that opens database.bin in readbinary mode
    if(file == NULL){       //check if previous file exists and can be opened, if not it print error message and exit
        printf("Error opening file");
        exit(1);        // terminate the program with exit status 1
    }
    fwrite(inrecord, sizeof(PERSON), 1, file);  // write PERSON record to the file
    fclose(file);   // close the file after use
}          

int main(void){ // main method that loops over user choices from 1-5
    int userOption; // declare variable of type int that corresponds to 1-5
    PERSON ppost;   // declare variable of type PERSON
    do{     // do while loop that prompts the user for input 
        printf("1. Create a new and delete old file.\n2.Add a new person to the file.\n3.Search for a person in the file\n4.Print out all in the file.\n5. Exit the program\n");
        scanf("%d", &userOption);   // scan for user input and set it to userOption variable


        switch (userOption){    // switch case that takes the previously set user option input
        case 1:         // case 1

            strcpy(ppost.firstname, "Gustav");  // set the dummy firstname when creating new file
            strcpy(ppost.famname, "Eriksson");  // set the dummy familkyname when creating new file
            strcpy(ppost.pers_number, "198501011234");  // set the dummy person number when creating new file
            write_new_file(&ppost); // call method write new file with the contents of ppost variable
            break;  // Exit the current case of the switch statement
        case 2: // case 2 of switch
            ppost = input_record(); // set the contents of ppost variable to the contents from the input record which takes user input for names
            append_file(&ppost);    // method call to append_file that takes the newly set conents of ppost and add it to the file contents
            break;  //Exit the current case of the switch statement
        case 3:     // if user inputs 3
            char name[20];  // declare variable name of size 20
            printf("Enter first name or family name to search: ");
            scanf("%s", name);  // scan for user input and set it to name
            search_by_firstname(name);  // method call to searchbyfirstname with argument name
            break;      //Exit the current case of the switch statement
        case 4: // user input 4
            printfile();    // method call to printfile that prints all of the contents of the file
            break;      //Exit the current case of the switch statement
        case 5: // user input 5
            printf("Exiting the program now");
            break;      //Exit the current case of the switch statement
        default:        // if any other input than 1-5 is given go here
            printf("Error. Invalid input. Please enter a number between 1-5\n");
            
        
    } 

    }while(userOption != 5);    // do while condition as long as input is not 5 keep looping
    return(0);  // return 0 to indicate sucess
} 
