/* Author: Tyler Bourque; tbourque2012
	Assignment 2: pH Values */

#include	<stdio.h>

int main( )
{
	double pH;

	printf( "Hello. Ever wonder if a certain pH level is either acidic or neutral?\nThis program will read any value and tell you the pH value.\n" );
	printf( "Please type in a value:" );
	scanf( "%lf", &pH );

	if (pH > 7 )	/* First, we start at the mid-point. Doing this, we can then follow it as a Yes or no argument; is the number greater than 7? YES= Read the next block. NO= Skip the next Block */
	{
		if( pH < 12 ) /* Is the Number Greater than 12? YES= Alkaline. NO= Move to next line of Code. */
		{
			printf( "That number is Alkaline.\n" );
		}

		else	/* Any other numbers above 12, means Very Alkaline */
		{
			printf( "That number is Very Alkaline.\n" );
		}
	}

	else if( pH == 7 ) /* Is the number 7? YES= That number is Neutral. NO= Move to the next block of code. */
	{
		printf( "That number is Neutral.\n" );
	}

	else if( pH < 7 ) /* Is the number less than 7? YES= it is acidic */
	{
		
		if( pH <= 2 ) /* Is the number less than or equal to 2? YES= is is very acidic. NO= it is just Acidic */
		{
			printf( "That number is Very Acidic.\n" );
		}
		
		else /* all other numbes between 7 and 2 are acidic */
		{
			printf( "That number is Acidic.\n" );
		}

		printf( "Thank you for using the program!\n" );
	}

	
	return 0;
}