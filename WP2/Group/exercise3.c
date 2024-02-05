#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// -----typedefs -------
typedef struct {
    char firstname[20];
    char famname[20];
    char pers_number[13]; // yyyymmddnnnc
} PERSON;

// Function declaration (to be extend)
PERSON input_record(void){
    PERSON temp;

    printf("Input first name for person: ");
    scanf("%19s", temp.firstname);

    printf("Input family name for person: ");
    scanf("%19s", temp.famname);

    printf("Input personal number for person (yyyymmddnnnnc): ");
    scanf("%12s", temp.pers_number);

    return temp;
}          
// Reads a person’s record.
void write_new_file(PERSON *inrecord){  // Creates a file and writes the first record
    FILE *file = fopen("database.bin", "wb");
    if(file == NULL){
        printf("Error opening file.\n");
        exit(1);
    }
    fwrite(inrecord, sizeof(PERSON), 1, file);
    fclose(file);
}         

void printfile(void){       // Prints out all persons in the file

    FILE *file = fopen("database.bin", "rb");
    if(file == NULL){
        printf("Error opening file, file does not exist");
        exit(1);
    }
    PERSON temp;
    while(fread(&temp, sizeof(PERSON), 1, file)){
        printf("%s %s %s \n", temp.firstname, temp.famname, temp.pers_number);
    }
    fclose(file);
}         

void search_by_firstname(char *name){               // Prints out the person if in list
    FILE *file = fopen("database.bin", "rb");
    if(file == NULL){
        printf("Error opening file, file does not exist");
        exit(1);
    }
    PERSON temp;
    while(fread(&temp, sizeof(PERSON), 1, file)){
        if (strcmp(temp.firstname, name) ==0 || strcmp(temp.famname, name) == 0){
            printf("Found persons: %s %s %s", temp.firstname, temp.famname, temp.pers_number);
        }
    }
    fclose(file);
}     

void append_file(PERSON *inrecord){
    FILE *file = fopen("database.bin", "ab");
    if(file == NULL){
        printf("Error opening file");
        exit(1);
    }
    fwrite(inrecord, sizeof(PERSON), 1, file);
    fclose(file);
}          // appends a new person to the file

int main(void){
    int userOption;
    PERSON ppost;
    do{
        printf("1. Create a new and delete old file.\n2.Add a new person to the file.\n3.Search for a person in the file\n4.Print out all in the file.\n5. Exit the program\n");
        scanf("%d", &userOption);


        switch (userOption){
        case 1: 

            ppost.firstname[0] = '\0';
            ppost.famname[0] = '\0';
            ppost.pers_number[0] = '\0';
            write_new_file(&ppost);
            break;
        case 2:
            ppost = input_record();
            append_file(&ppost);
            break;
        case 3:
            char name[20];
            printf("Enter first name or family name to search: ");
            scanf("%s", name);
            search_by_firstname(name);
            break;
        case 4:
            printfile();
            break;
        case 5:
            printf("Exiting the program now");
            break;
        default:
            printf("Error. Invalid input. Please enter a number between 1-5");
            
        
    } 

    }while(userOption != 5);
    return(0);
} 
