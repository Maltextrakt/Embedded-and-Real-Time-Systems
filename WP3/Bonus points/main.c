// import header file standard input output
#include <stdio.h>
#include <stdlib.h>     // import header file standard library

#define MAX_COLS 4  // define that sets the max columns allowed to 4
#define MAX_ROWS 4  // define that sets the max rows allowed to 4
#define BUFFER_SIZE 1024    // define that sets size of the buffer to 1024, which is enough to handle input for this task


int main (int argc, char *argv[]){  // main function that asks user for size of matrices and their content, then prints the sum of these

    int cols;   // declare int cols (columns)
    int rows;   // declare int rows

    printf("Input the size: ");
    //if statement that scans user input and returns an error if the number of inputs from user is not 2, 
    //or cols is less than or equal to 0, rows is less than or equal to 0, rows is bigger than the max
    // allowed rows, or cols is bigger than max allowed cols
    if(scanf("%d %d", &rows, &cols) != 2 || rows > MAX_ROWS || cols > MAX_COLS || cols <= 0 || rows <= 0){  
        printf("invalid");
        return 1;   // return 1 to indicate error
    }
    int c;  // declare variable c of type int
    while(c = getchar() != '\n' && c != EOF);   // clear the buffer until EOF is reached
    

    if(rows == 1 && cols == 1){ // if statement that ensures that the inputed rows and cols are 1
        printf("invalid");
        return 0;   // return 0 to indicate successful execution
    }

    int matr1[MAX_ROWS][MAX_COLS];  // declare 1st matrix and allocate maximum amount of memory needed
    int matr2[MAX_ROWS][MAX_COLS];  // declare 2nd matrix and allocate maximum amount of memory needed
    int sum[MAX_ROWS][MAX_COLS];    // declare the sum matrix and allocate maxmium amount of memory needed

    char input[BUFFER_SIZE];    // declare input of type char of size buffersize (1024)
    int num;    // declare variable num of type int that stores the current read number 
    int offset; // declare variable offset of type int that keeps track of the number of characters read by sscanf
    int i;  // variable i of type int used in the for loops
    int j;  // variable j of type inte used in the nested for loops

   
    printf("Input elements of matrix 1: ");
    fgets(input, sizeof(input), stdin); // read user input from keyboard and store it in the input buffer
    char *ptr = input;  // declare and initialize pointer to navigate through the input buffer 
    

    

    for(i=0; i<rows; i++){  // for loop that iterates over the size of the rows
        for(j=0; j<cols; j++){  // nested for loop that iterates over the size of the columns for each row
            if(sscanf(ptr, "%d%n", &num, &offset) == 1){    // if statement that scans user input, parses an integer from ptr and updates offset 
                matr1[i][j] = num;  // set the current number in the matrix1 to num (scanned from the user above)
                ptr = ptr + offset; // move the ptr offset amount of steps to check the next value in the input string
            } else {    // in all other cases go here
                printf("invalid");
                return 0;   // return 0 to indicate succesful execution
            }
            }
    }
    
        

    printf("Input elements of matrix 2: ");
    fgets(input, sizeof(input), stdin); // read user input from keyboard and store it in the input buffer
    ptr = input;    // set pointer to navigate through the input buffer 
    

    

    for(i=0; i<rows; i++){  // for loop that iterates over the size of the rows
        for(j=0; j<cols; j++){  // nested for loop that iterates over the size of the columns for each row
            if(sscanf(ptr, "%d%n", &num, &offset) == 1){    // if statement that scans user input, parses an integer from ptr and updates offset 
                matr2[i][j] = num;  // set the current number in the matrix 2 to num (scanned from the user above)
                ptr = ptr + offset; // move the ptr offset amount of steps to check the next value in the input string
            } else {    // in all other cases go here
                printf("invalid");
                return 0;   // return 0 to indicate succesful execution
            }
            }
    }

    for(int i=0; i<rows; i++){  // for loop that iterates over the size of the rows
        for(int j=0; j<cols; j++){  // nested for loop that iterates over the size of the columns for each row
            sum[i][j] = matr1[i][j] + matr2[i][j];  // set the sum number to that current place in the sum matrix to the sum of the corresponding values for matr1 and 2
        }
    }

    printf("The sum is: \n");
    for(int i=0;i<rows; i++){   // for loop that iterates over the size of the rows
        for(int j=0; j<cols; j++){  // nested for loop that iterates over the size of the columns for each row
            printf("%d ", sum[i][j]);   // print the sum value for each position in the sum matrix
        }
        printf("\n");   // print newline
    }

    return 0;   //return 0 to indicate succesful execution

}