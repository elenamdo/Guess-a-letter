#include <stdio.h>
#include <string.h>
#include "MyLib.h"

#define MAX_INPUT 81

int main(void)
{
    int FoundALetter = 0;
    char Guess = 'g';
    char *FindGuess;
    FindGuess = NULL;
    char Phrase[] = "This is my guess.";
    char PhraseCopy[20];
    char GuessALetterCopy[20];

    strcpy(GuessALetterCopy, Phrase);

    FindGuess = strchr(GuessALetterCopy, Guess);

    while (FindGuess != NULL){
        FoundALetter = 1;
        PhraseCopy[FindGuess - GuessALetterCopy] = Phrase[FindGuess - GuessALetterCopy];
        *FindGuess = '-';
        FindGuess = strchr(GuessALetterCopy, Guess);
    }

    printf("%s", PhraseCopy);

    return 0;
}
