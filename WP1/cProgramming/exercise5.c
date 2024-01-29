#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX 10 // Defines the maximum number of the values in the table
#define MAXNUMBER 20 // Defines the maximum value of random numbers
// ------ Function declarations ----------
// This function generates a set of random numbers
// and fills the table *tab with these numbers
void create_random(int *tab ){
    //int array = tab[MAX];
    for(int i=0; i<MAX; i++){
        tab[i] = rand() % MAXNUMBER;
        //printf("%d",tab[i]);
    }
}
// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
void count_frequency(int *tab, int *freq ){
    // initialize the frequency table content to 0 on all positions
    for(int j=0; j<MAXNUMBER; j++){
        freq[j] = 0;
    }

    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAXNUMBER; j++){
            if(tab[i] == j){
                freq[j] ++;
            }
        }
    }
}
// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq ){
    for(int i=0; i<MAXNUMBER; i++){
        if(freq[i] != 0 && i<9){
            printf("%d    ", (i+1));
            for(int j=0; j<freq[i]; j++){
                printf("X");
            }
            printf("\n");
        }else if(freq[i] != 0 && i<MAXNUMBER){
            printf("%d   ", (i+1));
            for(int j=0; j<freq[i]; j++){
                printf("X");
            }
            printf("\n");
        }else{
            //printf("skipped a number");
        }
    }
}

// ------ Function definitions ----------
// ------ Main --------------------------
// The main entry point for the program
//
// If you choose to go for the optional part
// Please modify it accordingly
int main (void){
    int table[MAX], n ;
    int frequency[MAXNUMBER];
    srand(time(NULL));
    create_random(table);
    count_frequency(table, frequency);
    draw_histogram(frequency);
    
}