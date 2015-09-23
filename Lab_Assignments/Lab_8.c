// Tyler Bourque; tbourque2012


/* Lab 8
Lab topic: Pointers – 
Lecture topics: pointers, arrays, and strings
Write a small program that calculates the sum and the difference of two integers with three user-defined functions:

//takes two integer arguments and returns the sum of the two arguments
int CalculateSum (int num1, int num2);

//takes two integer arguments and returns the difference of the two arguments
int CalculateDifference(int num1, int num2);

//takes two integer arguments and two integer pointer arguments 
//1. calculate the sum and stores the result in sumPtr
//2. calculate the difference and store the result in diffPtr 
void CalculateBoth(int num1, int num2, int*sumPtr, int *diffPtr);

Call all three functions from main.
Print the results in both the function definitions (value at) and back in main. */

#include	<stdio.h>

int CalculateSum( int, int );
int CalculateDifference( int, int );
void CalculateBoth( int, int, int * , int * );

int main( )
{
	int num1;
	int num2;
	int Sum;
	int Diff;
	int *sumPtr;
	int *diffPtr;




	printf( "Please type in an integer.\n" );
	scanf( "%d", &num1 );
	printf( "Please type in another integer.\n" );
	scanf( "%d", &num2 );

	Sum = CalculateSum( num1, num2 );
	Diff = CalculateDifference( num1, num2 );

	printf( "The Sum of the the two itegers is: %d\n", Sum );
	printf( "The Difference of the two integers is: %d\n", Diff );

	

	CalculateBoth( num1, num2, &sumPtr, &diffPtr );




	return 0;

}

int CalculateSum( int num1, int num2 )
{
	int Sum;
	
	Sum = num1 + num2;

	return Sum;
}

int CalculateDifference( int num1, int num2 )
{
	int  Diff;

	Diff = num1 - num2;

	return Diff;
}
void CalculateBoth( int num1, int num2, int *sumPtr, int *diffPtr  )
{
	*sumPtr = num1 + num2;

	*diffPtr = num1 - num2;

}