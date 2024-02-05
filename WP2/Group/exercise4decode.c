#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){

    if(argc != 2){
        printf("Error. Provide no mroe and no less than 1 argument.");
        return 1;
    }

    // unpack the argument (which is expected to be a hexadecimal), hence the 
    unsigned char packedByte = (unsigned char)strtol(argv[1], NULL, 16);

    // unpack values from the argument hexadeciaml (now unsigned char) using right shift bitwise
    // operators and masking. The masking compares the exact amount of bits for each variable, 
    // since gear_pos can be up to 4 it requires 3 bits, which is maximum 7, thus 0x07.
    int engine_on = (packedByte >> 7) & 0x01;
    // unpack values from the argument hexadeciaml (now unsigned char) using right shift bitwise
    // operators and masking.
    int gear_pos = (packedByte >> 4) & 0x07;
    // unpack values from the argument hexadeciaml (now unsigned char) using right shift bitwise
    // operators and masking.
    int key_pos = (packedByte >> 2) & 0x03;
    // unpack values from the argument hexadeciaml (now unsigned char) using right shift bitwise
    // operators and masking.
    int brake1 = (packedByte >> 1) & 0x01;
    // unpack values from the argument hexadeciaml (now unsigned char) using right shift bitwise
    // operators and masking.
    int brake2 = (packedByte) & 0x01;

    printf("Name        Value\n");
    printf("_________________\n");
    printf("engine_on      %d\n", engine_on);
    printf("gear_pos       %d\n", gear_pos);
    printf("key_pos        %d\n", key_pos);
    printf("brake1         %d\n", brake1);
    printf("brake2         %d\n", brake2);




    return 0;
}