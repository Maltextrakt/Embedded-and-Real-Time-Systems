// header import for standard input output
#include <stdio.h>
// header import for standard library, used for memory allocation, process control etc
#include <stdlib.h>
// header import for time, used for manipulating date and time
#include <time.h>

// main function that runs the whole game
int main(){
    // variable declarations
    
    // variable that counts how many times the user has guessed
    int nOfGuesses;
    // variable that represents the users input guess
    int userGuess;
    // variable that controls the max number of allowed guesses before the user loses
    int MAX_NUMBER = 10;
    // variable that determines if the user wants to keep playing the game or not after a round is finished
    int playAgain;
    
    // seed function that is required in order to generate new numbers with each rand call
    // it changes with time, and because time is always changing the seed is also changing
    // the current random generated number is static throughout one round of the game however, since
    // the rand function is only called once per game loop 
    srand(time(NULL));

    // do-while loop that runs once at first, and then in order to run again it checks if the user entered 
    // the number 1 after the round
    do{
        // initialize randomNumber variable that is set to a random number between 1 and 100 each time it is called
        // do + 1 because otherwise it would be between 0 and 99 since the counter starts at 0
        // utilizes the rand() function from library
        int randomNumber = (rand() %100) + 1;
        // set the variable nOfGuesses to 0
        nOfGuesses = 0;
        
        // prompt the user to start playing the game by printing out a message
        printf("Guess the number: ");
        printf("%d", randomNumber);

        // while-loop where the condition is that the counter nOfGuesses has to be less than the MAX_NUMBER
        // of guesses allowed
        while(nOfGuesses < MAX_NUMBER){
            // if statement that checks if the input from the user exists, and is between 1 and 100
            if(scanf("%d", &userGuess) != 1 || userGuess < 1 || userGuess > 100){
                printf("Please enter a number between 1 and 100: " );
                // while loop that clears the input until a newline is found
                while(getchar() != '\n');
                // continue is used to skip the current loop iteration and reprompts the user for a new input
                continue;
            }
            // increment the variable counter nOfGuesses (this is only reached after the above if check is passed)
            nOfGuesses ++;
            // if statement that checks if userguess is lower than the correct number
            if(userGuess < randomNumber){
                printf("You have guessed too low, guess again: ");
            // go here if userguess is bigger than the correct number
            } else if(userGuess > randomNumber){
                printf("You have guessed too high, guess again: ");
            // the other case (user guessed right)
            } else {
                printf("You have guessed %d number of times and your guess is correct!\n", nOfGuesses);
                // break the loop since the guess was correct 
                break;               
            }
    } 
    // if statement that checks if the limit of guesses has been reached and that the guess is not correct 
    // in the final guess
    if(nOfGuesses == MAX_NUMBER && userGuess != randomNumber){
        printf("You have reached the maxium number of guesses. The correct number you shouldve guessed was %d. ", randomNumber);
    }
    printf("Press 1 if you wanna play again or 2 if you wanna exit: ");
    // scan the stdin for user input
    scanf("%d", &playAgain); 

    // the while part of the do while. If the user inputs 1 the loop continues
    // I am using a do while in order to ensure that the program runs once without having to ask the
    // user if he/she wants to play
    } while (playAgain == 1);


}
