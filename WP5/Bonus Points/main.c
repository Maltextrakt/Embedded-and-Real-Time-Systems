// import standard input output header file
#include <stdio.h> 
// import standard library header file
#include <stdlib.h>

// main function that runs the core functionality of the program
int main(int argc, char *argv[]){
    // if statement ensuring that exactly 5 arguments are being provided
    if(argc != 6){
        printf("invalid");
        //return 0 to exit the program
        return 0;
    }

    // parsing the inputs from position 1 string to int
    int engine_on = atoi(argv[1]);
    // parsing the inputs from position 2 string to int
    int floor_pos = atoi(argv[2]);
    // parsing the inputs from position 3 string to int
    int door_pos = atoi(argv[3]);
    // parsing the inputs from position 4 string to int
    int brake1 = atoi(argv[4]);
    // parsing the inputs from position 5 string to int
    int brake2 = atoi(argv[5]);

    // setting the allowed limits on the variables
    // engine_on can be 0 or 1(1 bit)
    if(engine_on < 0 || engine_on > 1){
        printf("invalid");
        //return 0 to exit program if if statement is true
        return 0;
    } 
    // floor_post can be between 0 and 7(3 bits)
    if(floor_pos < 0 || floor_pos > 7){
        printf("invalid");
        // return 0 to exit program if if statement is true
        return 0;
    }
    // door_post can be between 0 and 2
    if(door_pos < 0 || door_pos > 2){
        printf("invalid");
        //return 0 to exit program if if statement is true
        return 0;
    }
    // brake1 can be 0 or 1
    if(brake1 < 0 || brake1 > 1){
        printf("invalid");
        // return 0 and exit if if statement is true
        return 0;
    }
    // brake2 can be 0 or 1
    if(brake2 < 0 || brake2 > 1){
        printf("invalid");
        // return 0 and exit if if statemenet is true
        return 0;
    }

    // using bitwise operators shift the input variables (now ints) to the corresponding positions in this
    // unsigned char (8 bits by default). Shift operator left is used in conjunction with the 'or' 
    // operant in order to combine the multiple binary values into a single byte
    unsigned char packedByte = (engine_on << 7) | (floor_pos << 4) | (door_pos << 2) | (brake1 << 1) | (brake2);

    printf("0x%02X", packedByte);

    // return 0 to exit program
    return 0;

}
