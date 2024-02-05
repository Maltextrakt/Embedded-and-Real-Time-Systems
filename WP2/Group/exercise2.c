// import header file standard input output
#include <stdio.h>
// import header file standard library
#include <stdlib.h>
// import header file for utilizing time functionality such as seeds
#include <time.h>
//#### Constants #####
// constant MAX set to 5, creates the linked list of size 5
#define MAX 5
// ##### typedefs ####
// structure q of type REGTYPE
typedef struct q{
    // declaration of int number
    int number;
    // declaration of pointer to a unique instance of the struct q next
    struct q *next;
    // declaration of pointer to a unique instance of the struct q previous
    struct q *prev;
// declare the type of struct, here REGTYPE
} REGTYPE;
// ##### Function declarations #####
// Declaration of function random_list, initialized at bottom of page
REGTYPE* random_list(void);
// declaration of function add_first, initialized at bottom of page
REGTYPE* add_first(REGTYPE* temp, int data);
//###### Main program #######
// main function that iterates over a linked list and then prints the content of each node
int main(int argc, char *argv[]){

    // declare and initialize variable nr to 0
    int nr=0;
    // 
    REGTYPE *act_post , *head=NULL;
    srand(time(0)); // Random seed
    head=random_list();
    act_post=head;
    while( act_post!=NULL){
    printf("\n Post nr %d : %d" , nr++, act_post->number);
    act_post=act_post->next;
    }
// --- Free the allocated memory ---
    while((act_post=head)!=NULL){
        head=act_post->next;
        free(act_post);
    }
return 0;
}

// ==== End of main ======================================
REGTYPE* random_list(void ){
    int nr, i=0;
    REGTYPE *top = NULL, *old, *item;
    for(i; i<MAX; i++){
        int randomNumber = rand() % 100;
        top = add_first(top, randomNumber);
    }
    return(top);
}
//==========================================================
REGTYPE* add_first(REGTYPE* temp, int data){
    REGTYPE *newNode = (REGTYPE*)malloc(sizeof(REGTYPE));
    if (newNode == NULL) {
        printf("Error. Memory allocation failed");
        return 0;
    }
    newNode->number = data;
    newNode->next = temp;

    if(temp != NULL){
        temp->prev=newNode;
    }

    newNode->prev = NULL;
    return newNode;
}