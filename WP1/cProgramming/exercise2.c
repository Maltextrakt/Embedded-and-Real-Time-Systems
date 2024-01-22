#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

    char input[100];
    char encryptedInput[100];

    char lowercaseAlphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
                         'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    char uppercaseAlphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
                         'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    int i;

    printf("Please enter a message to be encrypted: ");


while(fgets(input, sizeof(input), stdin)){

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
            encryptedInput[i] = lowercaseAlphabet[positionInAlphabet];
        } else if(currentLetter >='A' && currentLetter <= 'Z'){
            int positionInAlphabet = (currentLetter - 'A');
            positionInAlphabet = (positionInAlphabet + 13)%26;
            encryptedInput[i] = uppercaseAlphabet[positionInAlphabet];
        } else {
            encryptedInput[i] = currentLetter;
        }
    }
    encryptedInput[i] = '\0';
    printf("%s\n", encryptedInput);
}

    return 0;
}