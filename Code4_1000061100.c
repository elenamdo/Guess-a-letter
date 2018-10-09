#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "MyLib.h"

#define MAX_INPUT 81

int GuessALetter (char Phrase[], char PhraseCopy[])
{
    char Guess, UpperGuess;
    char *FindGuess;
    FindGuess = NULL;
    char GuessALetterCopy[MAX_INPUT];
    int FoundALetter = 0;
    int i;

    strcpy(GuessALetterCopy, Phrase);
    printf("%s", PhraseCopy);

    printf("\n\nPlayer 2: Guess a letter: ");
    Guess = getchar();
    getchar();


    if (Guess >= 97 & Guess <= 122){
        UpperGuess = Guess ^ 32;
    }
    else
        UpperGuess = Guess;

    for (i = 0; i <= strlen(Phrase); i++){
        if (GuessALetterCopy[i]>=97 & GuessALetterCopy[i]<=122)
            GuessALetterCopy[i] = GuessALetterCopy[i] ^ 32;
    }

    FindGuess = strchr(GuessALetterCopy, UpperGuess);

    while (FindGuess != NULL){
        FoundALetter = 1;
        PhraseCopy[FindGuess - GuessALetterCopy] = Phrase[FindGuess - GuessALetterCopy];
        *FindGuess = '-';
        FindGuess = strchr(GuessALetterCopy, UpperGuess);
    }
    return FoundALetter;
}

int main (void)
{
    char Phrase[MAX_INPUT];
    char UpperPhrase[MAX_INPUT];
    char PhraseCopy[MAX_INPUT];
    char Alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
    'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char *ReplaceIt;
    ReplaceIt = NULL;
    int Strikes = 0;
    int YourOut = 3;
    int i;

    printf("Welcome to ");

    ConvertDecimalToBinary(YourOut);

    printf(" STRIKES - YOU'RE OUT - the CSE version\n\n");
    printf("Player 2 -  Please look away\n\n");
    printf("Player 1 - Please enter the phrase that Player 2 will be guessing. \n");
    printf("           Enter a maximum of %d characters.\n", MAX_INPUT-1);
    printf("           Your phrase CANNOT contain a dash.\n\n");

    fgets(Phrase, MAX_INPUT, stdin);

    if ((strchr(Phrase, '-')) != NULL){
        printf("You broke the rules. We can't play. BYE!!");
        exit(1);
    }

    Phrase[strlen(Phrase)-1] = '\0';

    for (i = 0; i <= strlen(Phrase); i++){
        if (Phrase[i]>=97 & Phrase[i]<=122)
            UpperPhrase[i] = Phrase[i] ^ 32;
        else
            UpperPhrase[i] = Phrase[i];
    }

    strcpy(PhraseCopy, UpperPhrase);

    int j = 0;
    while (j<strlen(PhraseCopy)){
        ReplaceIt = strpbrk(PhraseCopy, Alphabet);
        if (ReplaceIt != NULL)
            *ReplaceIt = '-';
        j++;
    }

    printf("\nPlayer 2 - Here's the phrase you need to guess\n\n" );

    while ((strchr(PhraseCopy, '-') != NULL)){
        GuessALetter(Phrase, PhraseCopy);
        if (!((GuessALetter(Phrase, PhraseCopy)) && 0)){
            Strikes++;
            printf("Strike ");
            ConvertDecimalToBinary(Strikes);
            if (Strikes >= YourOut){
                ConvertDecimalToBinary(Strikes);
                printf("STRIKES - YOU'RE OUT!!");
                printf("Game over");
                return 0;
            }
        }
    }

      printf("You figured it out!!\n");
      printf("Player 1 entered the phrase ");
      printf("%s\n", Phrase);
      printf("Player 2 WINS!!!!");

      return 0;
}
