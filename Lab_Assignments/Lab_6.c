// Author: Tyler Bourque; tbourque2012


/*Lab topic: Loops – (counting loops)

Lecture topics: loops and pointers.

 

Create a program that asks the user to enter a number from 1 to 100.

Print the statement “FAU is awesome” the number of times entered by the user using a for loop.

Print the statement “Programming in C is fun” the same number of times using a while loop.

Print the statement “Florida beaches are beautiful” the same number of times using a do/while loop.*/

#include	<stdio.h>

int getNum( void );
void forLoop( int );
void whileLoop( int );
void doLoop( int );

int main( )
{
	int num;

	num = getNum( );

	forLoop( num );
	whileLoop( num );
	doLoop( num );


	
	return 0;
}

//Function Definitions

int getNum( void )
{
	int x;

	printf( "Type a number from 1 to 100.\n" );
	scanf( "%d", &x );
	printf( "\n\n" );

	return x;
}

void forLoop( int num )
{
	int iterations;

	for( iterations = num; iterations > 0; iterations--)
	{
		printf( "%d\tFAU is Awesome!\n", num );

		num--;
	}

	printf( "\n\n" );
}

void whileLoop( int num )
{
	int iterations;

	iterations = num; 

	while( iterations > 0 )
	{
		printf( "%d\tPrograming in C is Fun!\n", num);

		num--;
		iterations--;
	}

	printf( "\n\n" );
}

void doLoop( int num )
{
	int iterations;

	iterations = num;

	do
	{
	
		printf( "%d\tFlorida Beaches are Beautiful!\n", num);

		num--;
		iterations--;
	}
	while( iterations > 0 );

	printf( "\n\n" );
}