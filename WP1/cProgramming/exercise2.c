// import header file standard input output
#include <stdio.h>
// import string header file, used for string manipulation
#include <string.h>

// main function that "encrypts" character input and shifts all characters 13 positions to the right
// and then loops back around
int main(int argc, char *argv[]){

    // declare input variable list of type char, with size 100
    char input[100];
    // declare input variable list of type char, with size 100
    char encryptedInput[100];
    // declare and initialize lower case alphabet list of characters of size 26 
    char lowercaseAlphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
                         'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    // declare and initialize upper case alphabet list of characters of size 26
    char uppercaseAlphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
                         'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    // declare variable i of type int.
    int i;

    printf("Please enter a message to be encrypted: ");

// while loope that reads a variable from standard input until it ends or an error occurs
while(fgets(input, sizeof(input), stdin)){

    // for loop that runs until i comes across '\0'
    for(i=0; input[i] !='\0'; i++){

        // find what the current letter that is being operated on is
        // does this by taking the input that is located at [i] (which the program iterates via)
        char currentLetter = input[i];
        
        // if statement that checks for lowercase letters in the input
        // this comparison is valid because in c the letter 'a' etc corresponds to a integer ascii value
        if(currentLetter >='a' && currentLetter <='z'){
            // finds the position in the alphabet by utilizing ascii numbers. 
            // if the currrent letter is 'b' for example, that has value 98 in the ascii table
            // thus if we take 98-97 we get 1, i.e. the position of that letter in the alphabet is 1
            // when starting to count from 0
            int positionInAlphabet = (currentLetter - 'a');
            // set the new position to the place in the alphabe according to the encryption instructions,
            // in this case the position + 13
            // use modulo 26 (%26) here in order to wrap back to the start of the alphabet if the new position
            // integer exceeds 26
            // for example: current letter is 'y' which has position 24, thus the new position would be
            // 24+13=37. Then do 37%26 = 11. Thus the new position wont be 37(not allowed), but 11
            positionInAlphabet = (positionInAlphabet + 13) %26;
            // set the encrypted message on place i to the corresponding character in the lowercase
            // alphabet 13 positions before
            encryptedInput[i] = lowercaseAlphabet[positionInAlphabet];
        // else if that checks for upper case letters utilizing corresponding ascii values
        } else if(currentLetter >='A' && currentLetter <= 'Z'){
            // finds the position in the uppercase alphabet by siubtracting the ascii value of 'A' from the
            // current letter and set that value to the variable positionInAlphabet
            int positionInAlphabet = (currentLetter - 'A');
            // Same as in the case of lowercase alphabet, see line 43
            positionInAlphabet = (positionInAlphabet + 13)%26;
            // set the encrypted message on place i to the corresponding character in the uppercase
            // alphabet 13 positions before
            encryptedInput[i] = uppercaseAlphabet[positionInAlphabet];
        // else, covering all other cases
        } else {
            // if the current letter being operated on is not in the lower or uppcaase alphabets, dont 
            // encrypt it
            encryptedInput[i] = currentLetter;
        }
    }
    // null character in order to terminate the string stored in this array
    // without it the printf would not now where the the string ends
    encryptedInput[i] = '\0';
    printf("%s\n", encryptedInput);
}
    // return 0 in order to indicate successful exit.
    return 0;
}
