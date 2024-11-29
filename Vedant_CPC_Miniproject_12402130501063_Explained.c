#include <stdio.h>
#include <string.h>
#include <conio.h>

int main()
{
    // Variable declarations
    char Start, Exit, Word[6], Again, Guess[6], Playagain;
    int attempts = 5; // Maximum number of attempts allowed

Continu: // Label for the main menu
    clrscr(); // Clears the screen 
    printf("Hello and Welcome to Wordle (The Word Game)\n");
    printf("Code by Mandanka Vedant (12402130501063)\n\n\n");
    printf("Game guide: \n gray: The letter is not in the word. \n Yellow: The letter is in the word but missplaced. \n Green: The letter is in the word and its in currect position.");
    printf("\nType S to start: ");
    scanf(" %c", &Start);  // Read input to start the game

    // Handle invalid input for starting the game
    if (Start != 'S')
    {
        clrscr();
        printf("Do you want to exit the program?\n");
        printf("Type E to exit or Type C to continue: ");
        scanf(" %c", &Exit);  // Read input to exit or continue

        if (Exit == 'E') // Exit the program
        {
            goto exit;
        }
        else if (Exit == 'C') // Return to the main menu
        {
            goto Continu;
        }
        else // Handle invalid input
        {
            printf("Invalid input. Returning to the main menu...\n");
            goto Continu;
        }
    }
    else
    {
    Changeword: // Label for the word entry section
        clrscr();
        printf("Player 1: Enter a 5-letter word for Player 2 to guess: ");
        scanf("%5s", Word); // Read a 5-letter word

        clrscr();
        printf("Do you want to change your word?\n");
        printf("Type Y for Yes or N for No: ");
        scanf(" %c", &Again);  // Read input to confirm or change the word

        if (Again == 'Y') // If the player wants to change the word
        {
            goto Changeword;
        }
        else if (Again == 'N') // Proceed to the game
        {
            goto GameStart;
        }
        else // Handle invalid input
        {
            printf("Invalid input. Returning to word entry...\n");
            goto Changeword;
        }
    }

GameStart: // Label for the game loop
    clrscr();
    printf("You have %d attempts to guess the word!\n", attempts);

    while (attempts > 0) // Loop until attempts run out
    {
        printf("\nGuess the word: ");
        scanf("%5s", Guess);  // Read the player's guess

        // Initialize feedback and tracking array
        char feedback[6] = {'G', 'G', 'G', 'G', 'G', '\0'}; 
        int used[5] = {0}; // Tracks letters already matched

        // Check for correct letters in the correct position (Green)
        for (int i = 0; i < 5; i++)
        {
            if (Guess[i] == Word[i])
            {
                feedback[i] = 'X'; // Mark as correct position
                used[i] = 1;       // Mark as used
            }
        }

        // Check for correct letters in the wrong position (Yellow)
        for (int i = 0; i < 5; i++)
        {
            if (feedback[i] == 'X') continue; // Skip already matched letters
            for (int j = 0; j < 5; j++)
            {
                if (!used[j] && Guess[i] == Word[j]) // If letter matches
                {
                    feedback[i] = 'Y'; // Mark as correct letter, wrong position
                    used[j] = 1;       // Mark as used
                    break;
                }
            }
        }

        // Provide feedback to the player
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

        // Check if the player guessed the word correctly
        if (strcmp(Guess, Word) == 0)
        {
            printf("\nCongratulations! You guessed the word correctly.\n");
            goto playagain;
        }

        // Decrement attempts and provide feedback
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

playagain: // Label for replay option
    printf("\nDo you want to continue?");
    printf("\nType Y if yes and Type N if not: ");
    scanf(" %c", &Playagain); // Read input for replay

    if (Playagain == 'Y') // Replay the game
    {
        goto Continu;
    }
    else if (Playagain == 'N') // Exit the program
    {
        goto exit;
    }
    else // Handle invalid input
    {
        printf("Invalid input. Please enter Y or N.\n");
        goto playagain; 
    }

exit: // Label to exit the program
    return 0;
}