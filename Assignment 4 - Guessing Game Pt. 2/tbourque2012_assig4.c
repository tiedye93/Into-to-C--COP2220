// Tyler Bourque; tbourque2012

/* Course:		COP2220 - Introduction to Programming in C (Fall 2013)
Instructor:	Dr. Tondo

Assignment:	#4 (Guessing Game Part 2)
Due:		October 24th, 2013 by 11:59pm

Submit your source code to Blackboard by the deadline.

Please name your program in so that it includes both your FAU user ID and 
the assignment number.

For example:  jmulcah1_assig4.c


Assignment Objective:
----------------------

In this assignment, you will modify the letter-guessing game you made in the
last assignment. This is the 2nd part of a 2-part assignment.  In this part, 
you will demonstrate your knowledge about the following additional concepts:

- Modifying an existing program to extend its behavior
- File Input/Output (fprintf, fscanf)
- Looping (while/do-while)
- Conditional logic (switch) */



#include	<stdio.h>
#include	<time.h> // Need time.h to help generate a random letter

#define MAX_GUESSES 6

void Menu( void );
void Instructions( void );
char playGame( void );
char getChar( void );
char playAgain( void );
void filePrint( void );

int main( )
{
	char answer;
	char result;

	Menu( );

	// ***********Answer to playing*************
	while( answer = playAgain( ) )
	{
		switch( answer ) // The user decides to play the game
		{
			case 'y':
					printf( "Alright! Lets Play!\n\n" );

					Instructions( ); // Will jump to the Instuctions Function
					result = playGame( ); // Will jump to rhe playGame Function

				// ****************RESULT OF GAME*************************


					if( result == 'w' ) // After the function playGame returns 'w', the user then won the game.
					{
						printf( "\n\nHurray! You Win!\n\n\n" );	
					}

					if( result == 'l' ) // Vise versa with the function playGame if it returns 'l'.
					{
						printf( "Awwww. I'm sorry but you Lose!\n\n\n" );
					}

					break;
			case 'n':
					printf( "Too Bad! Maybe next time!\n" ); //The user decides to not play the game thus the program terminates
					
					return 0;

			case 'v':
					filePrint( );
				
					break;

			default:
					printf( "That was not one of the choices. Please try again.\n\n" );

					break;
				
		}

		Menu( );
	}
}


//****************Function Definitions**********************


void Menu( void )
{

	printf( "Hello! Welcome to Tyler's Alphabet Guessing game!\n\n" );
	printf( "To play:\ty\n" );
	printf( "To View last game:\tv\n" );
	printf( "To Quit:\tn\n" );
		 

}

void Instructions( void ) // This Function will print the instructions to the user and ask if they would like to play
{

	printf( "In this game, I will choose a random letter. You will have\n6 ATTEMPTS to guess for the correct letter.\n" );
	printf( "I will tell you if your choice is TOO HIGH or TOO LOW.\n" );
	printf( "If you guess correctly within the 6 ATTEMPTS, YOU WIN.\n" );
	printf( "If you do not guess correctly within the 6 ATTEMPTS, YOU LOSE.\n\n\n" );

}

char playGame( void ) //this function is the game itself. 
{
	int n;
	char ranChar;
	char letter;

	FILE *saveGame;
	n = MAX_GUESSES;
			
	ranChar = getChar( );
	saveGame = fopen( "gameLog.txt", "w" ); //opening File


	while( n > 0 )
	{ 


		printf( "Type in a letter:\n" );
		fprintf( saveGame, "Type in a Letter:\n" ); //writing to file

		scanf( " %c", &letter );
		fprintf( saveGame, " %c", letter ); // writing to file

		if( letter == ranChar )
		{
			printf( "Good Job!\n\n\n" );
			fprintf( saveGame, "Good Job!\n\n\n" ); //writing to file

			return 'w';	// If the letter typed in is the same as the random letter, this function will return 'w' which stands for win.
		}
		if( letter > ranChar )
		{
			printf( "\nChoose a Lower Letter\n\n" );
			fprintf( saveGame, "\nChoose a Lower Letter\n\n" ); // Printing to File
		}
		else
		{
			printf( "\nChoose a Higher Letter\n\n" );
			fprintf( saveGame, "\nChoose a Higher Letter\n\n" ); //Printing to file
		}

		n = n - 1; // This is how the counter for the number of tries goes down after each guess
	}

	printf( "You ran out of Tries!\n\n\n" );
	fprintf( saveGame, "You ran out of Tries!\n\n\n" ); //Writing to file

	return 'l'; // If the user ran out of tries, this function will return a 'l' which stands for lose.

	fclose( saveGame );
}

char getChar( void ) //this function generates a random letter using the library time.h
{
	char guess;

	time_t t = time( 0 );
	
	guess = 'a' + t % 26;

	return guess; 
}


char playAgain( void )
{
	char choice;

	scanf( " %c", &choice );

	return choice;
		 
}

void filePrint( void)
{
	char Char;
       FILE *saveGame;

       saveGame= fopen("gameLog.txt","r");

       if( saveGame == NULL ) 
    {
        printf( "could not open input file...\n" );
       
    }
       else
       {
         while ( fscanf( saveGame, "%c", &Char ) != EOF) 
         {
                printf("%c", Char); 
         }
             
       }
 
    fclose( saveGame ); 

}
