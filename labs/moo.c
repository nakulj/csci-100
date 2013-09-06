/* 
 * File:   moo.c
 * Author: Nakul Joshi
 * Created on September 23, 2010
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function prototypes
int runGame();						//Function for one game run
int processGuess(int *, int *);		//Function to find the number of bulls and cows in a game
int getDifficulty();				//Function to ask user for difficulty level
int compare(int *, int *);			//function to compare array contents
int isDuplicate(int, int *, int);	//function to see if a certain value occurs more than once in an array

int main(){

	int play=1,
		wins=0,
		trials=0;
	double successRate;
	srand(time(0));		//Generate random numbers using system time as a seed

	printf("Welcome to Moo! \n");	//Display instructions
	printf("The objective of the game is to guess the 4-digit code. \n");
	printf("The digits in the code are unique, so you'll never see a 4746, for example. \n");
	printf("A cow indicates a correct digit, in the wrong place. \n");
	printf("A bull indicates a correct digit in the correct place. \n");
	printf("Enter your guess, one digit at a time, and the game will tell you how many cows and how many bulls you had. \n");
	printf("Try to use the number of cows and bulls to get closer to the code and success! \n");

	while(play){
		trials++;
		wins+=runGame();
		printf("Would you like to play again?(1 for yes, 0 for no) \n");
		scanf("%d", &play);
	}//Stop if user inputs 0

	successRate=100.0*(double)wins/(double)trials;

	printf("Thank you for playing :) \n");
	printf("Your success rate was %.2f%% \n", successRate);
	printf("Goodbye! \n");
	return 0;
}

int runGame() {
    int code[4],
		guess[4],
        difficulty=getDifficulty(),
        i, j,
		temp, dup;
	for(i=0; i<4; i++){
		dup=1;
		while(dup){
			temp=10*rand()/RAND_MAX;
			dup=isDuplicate(temp, code, i);
		}//Before copying the digit to the array, check that it hasn't already been used
		code[i]=temp;
	}//Fill the code array with random digits
    for(i=10*difficulty; i>0; i--) {
        printf("Enter a guess(%d remaining) \n", i);
        for(j=0; j<4; j++)
			scanf("%d", &guess[j]);
        if(compare(guess, code)) {
            printf("Wohoo! You won! \n");
            return 1;
        }//The user wins if the guess matches the code
        if(i!=1)
            i+=processGuess(guess, code);	//If the guess doesn't match the code, find out how many cows/bulls the guess has,
											//Give the user another turn if an invalid guess was entered
    }//Allow user to guess so long as there are turn left
    printf("Sorry, you've used up all your guesses. You lose :( \n");
	return 0;
}

int processGuess(int *guess, int *code) {
    int cows=0,
        bulls=0;
	int i, j;
	for(i=1; i<4; i++) {
		if(isDuplicate(guess[i], guess, i)){
			printf("You can't repeat digits! Don't worry, I won't count this as a turn. \n");
			return 1;
		}
	}//Check if any of the digits have been repeated
	for(i=0; i<4; i++){
		for(j=0; j<4;j++){
			if(guess[j] == code[i]){
				if(i == j)
					bulls++;
				else
					cows++;
				break;
			}//Find whether the digit is a bull or a cow
		}//Match each digit of the guess against each digit of the code
	}//Check all digits of the guess

    printf("\t...%d bulls and %d cows \n", bulls, cows);
	return 0;
}

int getDifficulty() {
    int valid=0,
		difficulty=0;
    printf("Choose a difficulty level \n");	//Ask the user for difficulty level
    printf("1. Hard(10 chances) \n");
    printf("2. Medium(20 chances) \n");
    printf("3. Easy(30 chances) \n");
    while(!valid) {
        scanf("%d", &difficulty);
        if(1>difficulty || difficulty>3)
            printf("Invalid entry. Please enter a value between 1 and 3. \n");
        else
            valid=1;
    }//Keep asking until a valid digit is obtained
    switch(difficulty) {
        case 1: printf("Wow. You must be a pro! \n");
                break;
        case 2: printf("This shouldn't be too hard. \n");
                break;
        case 3: printf("You're new to this game, aren't you? \n");
				break;
    }
	return difficulty;//Return the difficulty
}

int compare(int *guess, int *code){
	int i;
	for(i=0;i<4;i++)
		if(code[i] != guess[i])
			return 0;
	//Compare all the elements of the array
	return 1;
}

int isDuplicate(int query, int *array, int limit){
	int i;
	for(i=0; i<limit; i++) {
		if(array[i] == query)
			return 1;
	}//Compare each element against the item to be checked
	return 0;
}


