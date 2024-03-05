#include <stdlib.h> // import header file for standard library
#include <stdio.h> // import header file for standard input output

typedef struct Node { // create new struct Node that creates nodes for a linked list
    int data;  // the data of the node
    struct Node *next; // pointer to the next node in the linked list
} Node; // end the definition of the structure

void append(Node **head, int newValue){ // method that appends a node to the linked list
    Node *newNode = (Node*)malloc(sizeof(Node)); // allocate memory size for the node that is going to be appended
    Node *last = *head; // set the pointer to last to the pointer of head

    newNode -> data = newValue; // assign passed value to the new node data field
    newNode ->next = NULL; // set the new nodes next pointer to null = currently the last node 

    if(*head == NULL){  // if the content of pointer to head is null..
        *head = newNode; // set the pointer to head to the new node 
        return; // return in order to dispaly succesful execution
    }

    while(last->next != NULL){ // while the last node is not null (find the last node in the linked list)
        last = last -> next; // move to the next node
    }
    last -> next = newNode; // attach the new node to the end of the linked list
}



int getFibonnaci(Node *head, int n){ // function that retrieves the nth fibbonaci number from the linked list
    int count = 1; // counter initialized to 1 for the first node
    Node *current = head; // start with the head of the list 
    while(current != NULL && count < n) { // go over list until the nth node or the end of the list 
        current = current -> next; // move to the next node
        count++; // increment the counter
    }
    if(current != NULL){ // if the current node is not null, we have found the nth node
        return current -> data; // return the data of the nth node (fibbonacci number)
    }
    return 0; // return 0 to indicate succesful execution
}

void createFibonacciSequence(Node **head, int n){ // method that creates the fibonacci linked list up to the nth number (n = the user input when calling the program) 

    if(n>=1) append(head,0); // base case for adding 0 if the linked list is greater or equal to 1
    if(n>=2) append(head, 1); // base case for adding 1 if the linked list is greater or equal to 2

    int first = 0; // declare and initialize first that starts at 0
    int second = 1;  // declare and initialize second that starts at 1
    int fib; // declare fib (fibonacci) that is the sum of first and second

    for(int i=3; i<=n; i++){ // iterate over the linked list
        fib = first + second; // set fib to the sum of first and second
        append(head, fib); // add the new fibonacci sum to the head of the list
        first = second; // set the first to the second
        second = fib; // set the second the fib, so that first and second are updated contonuously
    }
}

void freeLinkedList(struct Node *head){ // method that frees up the memory from the list after usage
    struct Node *temp; // pointer to a node used for traversing the list

    while(head != NULL){ // while the last node is not empty
        temp = head; // set temp to head
        head = head -> next; // set head to the head of the next node in the list
        free(temp); // free the current node (temp)
    }
};


int main(int argc, char *argv[]){ // main method that handles function calling 

    if (argc != 2){ // check so that the program is called with exactly 1 argument
        printf("error"); 
        return 0; // return 0 to indicate success
    }

    int n = atoi(argv[1]); // use atoi to turn the argument in to an int
    Node *head = NULL; // set the pointer to head to null

    createFibonacciSequence(&head, n); // create the linked list
    int fibbonaciNumber = getFibonnaci(head, n); // retrieve the nth fibonacci
    printf("%d\n", fibbonaciNumber); // print the number

    freeLinkedList(head); // free the list

    return 0; // return 0 to indicate successful execution
}