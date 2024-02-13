#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX 10

int main(int argc, char *argv[]){

    int array[MAX];
    srand(time(NULL));
    int *ptr = array;
    

    for(int i=0; i<MAX; i++){
        array[i] = rand() % 100;
    }

    printf("The value of the address of the array is: %p\n", ptr);
    printf("First integer in the array is: %d\n", array[0]);
    printf("The last integer of the array is: %d\n", array[MAX-1]);
    printf("The size of an integer is: %d\n", sizeof(int));
    printf("The size of the whole array in bytes is: %d\n", sizeof(array));

    printf("Printing the whole array 1 by 1: \n");
    for(int i=0; i<MAX; i++){
        printf("%d\n", *ptr);
        ptr++;
    }

    //reset the pointer to the start of the array again after looping through
    ptr = array;

    printf("Printing the whole array after multiplying by 2: \n");
    for(int i=0; i<MAX; i++){
        printf("%d\n", (*ptr) * 2);
        ptr++;
    }
    

    return 0;
}