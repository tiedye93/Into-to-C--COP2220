// Tyler Bourque; tbourque2012


/* Course:		COP2220 - Introduction to Programming in C (Fall 2013)
Instructor:	Dr. Tondo

Assignment:	#5 (Hangman Part 1)
Due:		November 19th, 2013 by 11:59pm

Submit your source code to Blackboard by the deadline.

Please name your program in so that it includes both your FAU user ID 
and the assignment number.

For example:  jmulcah1_assig5.c

+-----------------------+
| Assignment Objective: |
+-----------------------+

In this assignment, you will create an interactive program that lets the 
user play the game of Hangman, demonstrating your knowledge about the 
following concepts:

- Standard Input/Output (printf, scanf)
- Functions & Function Prototypes (declaring, defining and invoking)
- Conditional logic (if/else)
- Loops (while, do/while, for)
- File I/O


+--------------------+
| General algorithm: |
+--------------------+

- Read a single word (a string of characters) from an input file, and 
  give the player a maximum number of chances to guess all of the 
  letters in that word, as described below.

- If the player has guessed all of the letters in the word before running 
  out of chances, the game is over and they are congratulated.

- If the player runs out of chances, but some letters have not been guessed,
  the game is over, and they are consoled and shown the whole word.

- If the player guesses a letter that is not in the word, a message is printed
  to that effect and they get to guess again, unless they have used up all
  their chances.

- If the player guesses a letter that is in the word, every occurrence of that
  letter is considered to have been guessed, and they get to guess another 
  letter, unless the entire word has been guessed, or they have run out of 
  chances.

- The player continues to guess letters until the entire word has been guessed,
  or they have run out of chances.

- Once the game is over, you should thank the user for playing, close the input
  file, and exit the program. */

#include    <stdio.h>
#include    <string.h>
#include    <ctype.h>

#define MAXWORD 10
#define INCORRECT_GUESSES 7

/* Prototypes */
void fill_array( char *, int, char ); // Fills theArray with howMany copies of theLetter
int get_letter( char *, char * ); // Get char from player, checks the letter, shows progress so far
int letter_in_word( char *, char *, char ); // Check if letter is in word, updates progress so far
void lower_string( char * ); // Convert the word to lowercase
void play( char * ); // Play one game


/* Function definitions */

int main( )
{
	char theWord[ MAXWORD ];
	FILE *wordBank;
	int n = 0;
    
	wordBank = fopen( "guesswords.txt", "r" );

    if( wordBank == NULL )
    {
        printf( "Could not open input file...\n" );
        return -1;
    }

	fscanf( wordBank, "%s", &theWord[ n ] );

	lower_string( &theWord );

	play( &theWord );

	fclose( wordBank );

	return 0;
}


/* *********************************************************************** */

// Fills theArray with howMany copies of theLetter
void fill_array( char *theArray, int howMany, char theLetter )
{
	int i;

	for( i = 0; i < howMany; i++  )
	{
		theArray[ i ] = theLetter;
	}

	theArray[ howMany ] = '\0';

	howMany = 0;

	while( theArray[ howMany ] != '\0' )
	{
		putchar( theArray[ howMany++ ] );
	}

	printf( "\n" );
}

/* *********************************************************************** */

// Get char from player, checks the letter, shows progress so far
int get_letter( char *theWord, char *soFar )
{
	char theLetter;
	char result;

	printf( "Please type in a letter to guess:\n" );
	scanf( " %c", &theLetter );

	lower_string( &theLetter );

	result = letter_in_word( theWord, soFar, theLetter );

	return result; 
}

/* *********************************************************************** */

// Check if letter is in word, updates progress so far
int letter_in_word( char *theWord, char *soFar, char theLetter )
{
	int i;
	int matches = 0;

	for( i = 0; theWord[ i ] != '\0'; ++i )
	{
		if( theWord[ i ] == theLetter )
		{
			soFar[ i ] = theWord[ i ];
			++matches;
		}
	}
	if( matches == 0 )
	{
		printf( "\nI'm Sorry, But that Letter is not in the Word!\n");


		return 0;
	}
	else
	{
		printf( "\nYAY! That Letter is in the Word!\n" );
		printf( "The Word you are trying to figure out so far is:\n\n" );
		printf( "%s\n\n", soFar );

		return 1;
	}
}

/* *********************************************************************** */

// Convert the word to lowercase
void lower_string( char *someWord )
{
	int i;

	for( i = 0; i < MAXWORD; i++ )
	{
		someWord[ i ] = tolower( someWord[ i ] );
		if( someWord[ i ] == '\0' )
		{
			break;
		}
	}
}

/* *********************************************************************** */

// Play one game
void play( char *theWord )
{
	int numGuess = INCORRECT_GUESSES;
	char soFar[ MAXWORD ];
	int guessesLeft;
	int result;


	fill_array( soFar, strlen( theWord ), '*' );

	for( ; numGuess > 0; numGuess-- )
	{
		printf( "You have %d guesses left\n\n", numGuess );

		result = get_letter( theWord, soFar );

		if( result == 1 )
		{
			if( strcmp( soFar, theWord ) == 0 )
			{
				printf( "HOORAY! YOU FIGURED OUT MY WORD!\n" );
				printf( "The word you guessed correctly was, in fact, %s.\n", theWord );
				printf( "Now send me some Money so my code can be used by everyone!\n\n" );

				break;

			}
			
			numGuess++;
		}
		
		else if( result == 0 )
		{
			printf( "Guess again!\n\n" );
			printf( "The Word you are trying to figure out so far is:\n\n" );
			printf( "%s\n\n", soFar );
		}
	}

	if( numGuess == 0 )
	{
		printf( "I'm Sorry, but you did not find the word in the amount of guesses!\n\n" );
		printf( "The Word you had to figure out was\t%s\n\n", theWord ); 
		printf( "Come play again!\n" );
	}

}



// End of program