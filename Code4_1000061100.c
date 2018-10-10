/* Maria Maldonado 1000061100 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "MyLib.h"

#define MAX_INPUT 81

int GuessALetter (char Phrase[], char PhraseCopy[], char UpperPhrase[])
{
    char Guess;
    char *FindGuess;
    FindGuess = NULL;
    char GuessALetterCopy[MAX_INPUT];
    int FoundALetter = 0;

    strcpy(GuessALetterCopy, UpperPhrase);
    printf("\n\n%s", PhraseCopy);

    printf("\n\nPlayer 2: Guess a letter: ");

    Guess = getchar();
    getchar();
    Guess = toupper(Guess);

    FindGuess = strchr(GuessALetterCopy, Guess);

    while (FindGuess != NULL)
    {
        FoundALetter = 1;
        PhraseCopy[FindGuess - GuessALetterCopy] = Phrase[FindGuess - GuessALetterCopy];
        *FindGuess = '-';
        FindGuess = strchr(GuessALetterCopy, Guess);
    }

    return FoundALetter;
}

int main (void)
{
    char Phrase[MAX_INPUT];
    char PhraseCopy[MAX_INPUT];
    char UpperPhrase[MAX_INPUT];
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

    if ((strchr(Phrase, '-')) != NULL)
    {
        printf("\nYou broke the rules. We can't play. BYE!!\n\n");
        exit(1);
    }

    Phrase[strlen(Phrase)-1] = '\0';

    for (i = 0; i <= strlen(Phrase); i++)
    {
        UpperPhrase[i] = toupper(Phrase[i]);
    }

    strcpy(PhraseCopy, UpperPhrase);

    ReplaceIt = strpbrk(PhraseCopy, Alphabet);

    while (ReplaceIt != NULL)
    {
        *ReplaceIt = '-';
        ReplaceIt = strpbrk(PhraseCopy, Alphabet);
    }

    printf("\nPlayer 2 - Here's the phrase you need to guess\n\n" );

    do
    {
        if (GuessALetter(Phrase, PhraseCopy, UpperPhrase) == 0)
        {
            Strikes++;
            printf("\nStrike ");
            ConvertDecimalToBinary(Strikes);
            if (Strikes >= YourOut)
            {
                printf("\n\n");
                ConvertDecimalToBinary(Strikes);
                printf(" STRIKES - YOU'RE OUT!!\n");
                printf("\nGame over\n\n");
                return 0;
            }
        }
    }
    while ((strchr(PhraseCopy, '-') != NULL));

    printf("\n\nYou figured it out!!\n");
    printf("\nPlayer 1 entered the phrase\n ");
    printf("\n%s\n", Phrase);
    printf("\nPlayer 2 WINS!!!!\n\n");

      return 0;
}
