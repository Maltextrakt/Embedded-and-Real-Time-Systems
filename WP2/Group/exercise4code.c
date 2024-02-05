#include <stdio.h>
#include <stdlib.h>


int parse_input(void){
}
int main(int argc, char *argv[]){

    if(argc != 6){
        printf("Error. Give no more and no less than 5 arguments.");
        return 1;
    }

    // parsing the inputs from position 1 string to int
    int engine_on = atoi(argv[1]);
    // parsing the inputs from position 2 string to int
    int gear_pos = atoi(argv[2]);
    // parsing the inputs from position 3 string to int
    int key_pos = atoi(argv[3]);
    // parsing the inputs from position 4 string to int
    int brake1 = atoi(argv[4]);
    // parsing the inputs from position 5 string to int
    int brake2 = atoi(argv[5]);

    if(engine_on < 0 || engine_on > 1){
        printf("Error. Set engine_on to 0 or 1");
        return 1;
    } 
    if(gear_pos < 0 || gear_pos > 4){
        printf("Error. Set gear_pos to a number between 0 and 4");
        return 1;
    }
    if(key_pos < 0 || key_pos > 2){
        printf("Error. Set key_pos to a number between 0 and 2");
        return 1;
    }
    if(brake1 < 0 || brake1 > 1){
        printf("Error. Set brake_1 to 0 or 1");
        return 1;
    }
    if(brake2 < 0 || brake2 > 1){
        printf("Error. Set brake_2 to 0 or 1");
        return 1;
    }

    // using bitwise operators shift the input variables (now ints) to the corresponding positions in this
    // unsigned char (8 bits by default). Shift operator left is used in conjunction with the 'or' 
    // operant in order to combine the multiple binary values into a single byte
    unsigned char packedByte = (engine_on << 7) | (gear_pos << 4) | (key_pos << 2) | (brake1 << 1) | (brake2);

    printf("%02X", packedByte);

    return 0;

}
