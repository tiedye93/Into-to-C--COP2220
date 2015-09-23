/* Tyler Bourque; tbourque2012
Course:		COP2220 - Introduction to Programming in C (Fall 2013)
Instructor:	Dr. Tondo

Assignment:	#3 (Guessing Game Part 1)
Due:		October 3rd, 2013 by 11:59pm

Assignment Objective:
----------------------

In this assignment, you will create an interactive number-guessing game. This
will be a 2-part assignment.  In this part (due next week), you will demonstrate
your knowledge about the following concepts:

- Standard Input/Output (printf, scanf)
- Functions & Function Prototypes (declaring, defining and invoking)
- Conditional logic (if/else)

Next week, you will modify this program to add looping and file I/O logic.


Assignment Details:
-------------------

- Create a program that generates a "random" letter, and gives the user
  up to 6 chances to guess that letter.

- If the player guesses the right answer before they run out of chances, 
  the game is over and they are congratulated.

- If the player guesses wrong, your program will tell them whether their 
  answer is too high or if it is too low.  Using a loop (i.e., WHILE),
  the user gets to guess again, until they run out of chances.

- If the player guesses wrong on the 6th try, the game is over, 
  ad the player is consoled.  The correct answer is displayed.

- Once the game is over, you should thank the user for playing, and exit.

- In your code, use braces and indentation appropriately.

- Name your variables with meaningful names whenever possible, instead of "x".

- Make sure that you include comments in your program to make it more readable.  

  *** Please include a series of comments at the top of your program identifying 
  this this course, your name and the assignment, as well as a short description 
  of what the program accomplishes.  Also include comments that briefly describes 
  what the program is doing, along the way.  They can be simple, but descriptive.
  
  The idea is to make the flow of your program readable by humans, even if they 
  do not understand C. 

  NOTE:  You do not need to comment every line of code.  If you have doubled the 
         number of characters in yours assignment, you may have overdone it.  

         Think about how you would organize a term paper, and you have the 
         general idea. */


#include	<stdio.h>
#include	<time.h> // Need time.h to help generate a random letter

#define MAX_GUESSES 6

char Instructions( void );
char playGame( void );
char getChar( void );
char getLetter( void );

int main( )
{
	char answer;
	char result;

	answer = Instructions( ); // Will jump to the Instuctions Function

	// ***********Answer to playing*************

	if( answer == 'y' ) // The user decides to play the game
	{
		printf( "Alright! Lets Play! Let's see....\n\n" );

		result = playGame( ); // Will jump to rhe playGame Function
	}
	
	if ( answer == 'n' ) //The user decides to not play the game thus the program terminates
	{
		printf( "Too Bad! Maybe next time!\n" );
		return 0;
	}

// ****************RESULT OF GAME*************************

	if( result == 'w' ) // After the function playGame returns 'w', the user then won the game.
	{
		printf( "Hurray! You Win!\n" );
		printf( "Hope to play with you again soon!\n" );
	}

	if( result == 'l' ) // Vise versa with the function playGame if it returns 'l'.
	{
		printf( "Awwww. I'm sorry but you Lose!\n" );
		printf( "Try again sometime!\n" );
	}

	return 0; //Terminate Program
}

//****************Function Definitions**********************

char Instructions( void ) // This Function will print the instructions to the user and ask if they would like to play
{
	char answer;
	printf( "Hello! Welcome to Tyler's Alphabet Guessing game!\n" );
	printf( "In this game, I will choose a random letter. You will have\n6 ATTEMPTS to guess for the correct letter.\n" );
	printf( "I will tell you if your choice is TOO HIGH or TOO LOW.\n" );
	printf( "If you guess correctly within the 6 ATTEMPTS, YOU WIN.\n" );
	printf( "If you do not guess correctly within the 6 ATTEMPTS, YOU LOSE.\n\n" );
	
	printf( "Would you like to play? y for YES n for NO\n" );
	scanf( " %c", &answer );

	return answer;

}

char playGame( void ) //this function is the game itself. 
{
	int n;
	char ranChar;
	char letter;

	n = MAX_GUESSES;
			
	ranChar = getChar( );

	while( n > 0 )
	{ 
		letter = getLetter( );

		if( letter == ranChar )
		{
			return 'w';	// If the letter typed in is the same as the random letter, this function will return 'w' which stands for win.
		}
		if( letter > ranChar )
		{
			printf( "Choose a Lower Letter\n\n" );
		}
		else
		{
			printf( "Choose a Higher Letter\n\n" );
		}

		n = n - 1; // This is how the counter for the number of tries goes down after each guess
	}


	return 'l'; // If the user ran out of tries, this function will return a 'l' which stands for lose.
}

char getChar( void ) //this function generates a random letter using the library time.h
{
	char guess;

	time_t t = time( 0 );
	
	guess = 'a' + t % 26;

	return guess; 
}

char getLetter( void ) // This function will allow the user to type in a letter. It will then return that letter
{
	char letter;

	printf( "Type in a letter:\n" );

	scanf( " %c", &letter );

	return letter;
}
