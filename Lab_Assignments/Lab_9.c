// Tyler Bourque; tbourque2012

/*Lab 9
            Lab topic: Arrays –
Lecture topics: arrays and c-style strings.
 
Write a small program that fills an array of doubles with user input, prints the doubles on the screen in a column, and adds up all the doubles in the array and prints the sum onto the screen.
- Declare an array of doubles of size 20.
- Ask the user how many doubles to enter <= 20.
- Use a loop to read the doubles into the array from the user.
- Use a loop to print the array onto the screen in a column.
- Use a loop to add up all the items in the array and store the sum
- print the sum onto the screen

**USE FUNCTIONS */

#include	<stdio.h>
#define		MAXLINE		20

void doubleNum( int );
void sumDouble( int, double * );

int main( )
{
	int numofDouble;


	printf( "Please type in how many doubles you want. Please make it less than 20.\n" );
	scanf( "%d", &numofDouble );

	doubleNum( numofDouble );






	return 0;
}

void doubleNum( int numofDouble )
{
	int n;
	double myDouble[ MAXLINE ];
	double myDoub;

	for( n = 0; n < numofDouble; n++ )
	{
		printf( " Please type in a double: " );
		scanf( "%lf", &myDoub );

		myDouble[ n ] = myDoub;

	}

	printf( "\n\n" );

	for( n = 0; n < numofDouble; n++ ) 
	{
		printf( "%6.2f\n", myDouble[ n ] );
	}

	sumDouble( numofDouble, &myDouble );

}

void sumDouble( int numofDouble, double *myDouble )
{
	int n;
	double sum = 0;

	for( n = 0; n < numofDouble; n++ ) 
	{
		sum += myDouble[ n ];
	}
	
	printf( "\nThe sum of all the numbers typed in is\t%6.2f.\n\n", sum );
}

