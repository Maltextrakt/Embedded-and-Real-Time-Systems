#include <stdio.h> // import standard input output header
#include <stdlib.h> // import standard library header

void swap(int *x, int *y){ // swap function that swaps 2 ints
    int temp = *x; // set temporary to the value pointed to by x
    *x = *y; // set value pointed to by y to the value pointed to by x
    *y = temp; // set value pointed to by temp to the value pointed to by y
}


int search_number(int number, int tab[], int size){ // find number in array of ints and return its index
    
    for(int i=0; i<size; i++){ // for loop, iterates over size of the array
        if(tab[i] == number){ // if current element matcher number
            return i; // return current index
        } 
    }
    return -1; // otherwise return -1, indixating not found
}

void sort(int number, int tab[]){ // selection sort function, sorts from lowest to biggest
    int minimumIndex; // index for smallest element found

    for(int i = 0; i<number-1; i++){ // for loop, iterates over every element except last one
        minimumIndex = i; // set min index to current index
        for(int j=i+1; j<number; j++){ // nested for loop, loop over unsorted part of the array
            if(tab[j] < tab[minimumIndex]){ // if found smaller element
                minimumIndex = j; // uodate min index to current index

            }
        } 
        if(minimumIndex != i){ // if if a smaller element was found
            swap(&tab[minimumIndex], &tab[i]); // swap current elemetn with smallest found
        }
    }
      for(int i=0; i<number; i++){ // loop through the sorted array
        printf("%d ", tab[i]); // print elements of the sorted array
    }
}


int main(int argc, char *argv[]){ // main function
    
    int test[] = {1, 2, 34, 5, 67, 3, 23, 12, 13, 10}; // hardcoded array to test with

    printf("The index of the unsorted array number is: %d", (search_number(34, test, 10))); // print index of number with function call 
    printf("\n");

    printf("The sorted array is: ");
    sort(10, test); // function call to sort the array, which also prints it
    

    return 0; // return 0 to indicate success
}

