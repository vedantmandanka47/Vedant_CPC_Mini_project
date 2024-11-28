#include <stdio.h>
#include <string.h>
#include <conio.h>

int main()
{
    char Start, Exit, Word[6], Again, Guess[6], Playagain;
    int attempts = 5;

Continu:
    clrscr(); // Clears the screen (use system("cls") if clrscr is unavailable)
    printf("Hello and Welcome to Wordle (The Word Game)\n");
    printf("Code by Mandanka Vedant (12402130501063)\n\n\n");
    printf("Game guide: \n gray: The letter is not in the word. \n Yellow: The letter is in the word but missplaced. \n Green: The letter is in the word and its in currect position.");
    printf("Type S to start: ");
    scanf(" %c", &Start);  // Added space to handle trailing newline

    if (Start != 'S')
    {
        clrscr();
        printf("Do you want to exit the program?\n");
        printf("Type E to exit or Type C to continue: ");
        scanf(" %c", &Exit);  // Added space before %c to handle newline

        if (Exit == 'E')
        {
            goto exit;
        }
        else if (Exit == 'C')
        {
            goto Continu;
        }
        else
        {
            printf("Invalid input. Returning to the main menu...\n");
            goto Continu;
        }
    }
    else
    {
    Changeword:
        clrscr();
        printf("Player 1: Enter a 5-letter word for Player 2 to guess: ");
        scanf("%5s", Word);

        clrscr();
        printf("Do you want to change your word?\n");
        printf("Type Y for Yes or N for No: ");
        scanf(" %c", &Again);  

        if (Again == 'Y')
        {
            goto Changeword;
        }
        else if (Again == 'N')
        {
            goto GameStart;
        }
        else
        {
            printf("Invalid input. Returning to word entry...\n");
            goto Changeword;
        }
    }

GameStart:
    clrscr();
    printf("You have %d attempts to guess the word!\n", attempts);

    while (attempts > 0)
    {
        printf("\nGuess the word :");
        scanf("%5s", Guess);  

        // Feedback logic
        char feedback[6] = {'G', 'G', 'G', 'G', 'G', '\0'}; 
        int used[5] = {0}; 
        for (int i = 0; i < 5; i++)
        {
            if (Guess[i] == Word[i])
            {
                feedback[i] = 'X'; 
                used[i] = 1;       
            }
        }
        for (int i = 0; i < 5; i++)
        {
            if (feedback[i] == 'X') continue; 
            for (int j = 0; j < 5; j++)
            {
                if (!used[j] && Guess[i] == Word[j])
                {
                    feedback[i] = 'Y'; 
                    used[j] = 1;       
                    break;
                }
            }
        }
        printf("Feedback: ");
        for (int i = 0; i < 5; i++)
        {
            if (feedback[i] == 'X')
            {
                printf("Green ");
            }
            else if (feedback[i] == 'Y')
            {
                printf("Yellow ");
            }
            else
            {
                printf("Gray ");
            }
        }
        printf("\n");
        if (strcmp(Guess, Word) == 0)
        {
            printf("\nCongratulations! You guessed the word correctly.\n");
            goto playagain;
        }

        attempts--;
        if (attempts > 0)
        {
            printf("\nYou have %d attempts remaining.\n", attempts);
        }
        else
        {
            printf("\nGame Over! The correct word was: %s\n", Word);
        }
    }
    playagain:
    printf("\nDo you want to continue?");
    printf("\nType Y if yes and Type N if not: ");
    scanf(" %c", &Playagain); // Added space before %c to handle newline

    if (Playagain == 'Y') {
        goto Continu;
    } else if (Playagain == 'N') {
        goto exit;
    } else {
        printf("Invalid input. Please enter Y or N.\n");
        goto playagain; // Prompt again for valid input
    }
exit:
    return 0;
} 