// Tyler Bourque; tbourque2012
/* Lab 7
Lab topic: Loops (sentinel loop)
Lecture topics: pointers and arrays.
 
Create a program that asks the user to enter a number until the user enters a -1 to stop
as long as the number is not -1,  print the number on the screen
When the user enters a -1 print the message “Have a Nice Day :)” and end the program */

#include	<stdio.h>

int main( )
{
	int num;
	int *p;

	printf( "This program will run continuously until you type in -1 into the program. Enjoy!\n\n" );

	do
	{
		p = &num;

		printf( "Please type in a number:" );
		scanf( "%d", &num );
		printf( "Your number is %d\n\n", *p );

	}
	while( num != -1 );

	printf( "Have a Nice Day :)\n\n" ); 

	return 0;
}