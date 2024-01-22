#include <stdio.h>


int main(int argc, char *argv[]){

    char a[25] = "You entered number 1\n";
    char b[25] = "You entered number 2\n";
    char c[25] = "You entered number 3\n";
    char d[25] = "You entered number 4\n";
    char e[25] = "You entered number 5\n";

    int input;
    

    do {

        printf("Please enter a number between 1 and 5: ");
        scanf("%d", &input);

        if(input == 1){
            printf(a);
        } else if(input == 2){
            printf(b);
        } else if(input == 3){
            printf(c);
        } else if(input == 4){
            printf(d);
        } else if(input == 5){
            printf(e);
        }
    } while (input >0 && input <6);

    return 0;
}