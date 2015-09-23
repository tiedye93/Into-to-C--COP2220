/*Lab topic: Functions –
Lecture topics this week: functions, conditions, file processing, loop intro 
Break up the program (areas) from last week into one main function and 4 user-defined functions:

// gets an integer from the user and returns it
// make 3 calls to this function: 
// get the length of the rectangle from the user and return it to main 
// get the width of the rectangle from the user and return it to main 
// get the radius of the circle from the user and return it to main
int GetNum(void);

// takes two arguments, the length and width of the rectangle and returns the area 
int CalculateAreaRec(int length, int width);

// takes one argument, the radius of the circle and returns the area 
double CalculateAreaCir(int radius);*/

/* Author: Tyler Bourque; tbourque2012*/

#include	<stdio.h>

//Function Prototypes

int GetNum( int x );
int CalculateAreaRec( int length, int width );
double CalculateAreaCir( int radius );



int main( )
{
	int length, width, areaRec, radius;
	double areaCir;

	printf( "This program will calculate the area of a Rectangle & a Circle\n" );

	printf( "Please type in the length of a rectangle:" );
	length = GetNum( 1 );

	printf( "Please type in the width of a rectangle:" );
	width = GetNum( 1 );


	areaRec = CalculateAreaRec( length, width );

	printf( "A Rectangle with the length of %d and the width of %d will have an area of %d.\n", length, width, areaRec );

	printf( "Please type in the Radius of a Circle:" );
	radius = GetNum( 1 );

	areaCir = CalculateAreaCir( radius );

	printf( "The rectangle with the length being %d and the width being %d will have an area of %d.\n", length, width, areaRec );
	printf( "The area of a Circle with the radius of %d is %lf.\n", radius, areaCir );
		
	return 0;

}

// Function Declarations

int GetNum( int x )
{

	scanf( "%d", &x );

	return x;
}

int CalculateAreaRec( int length, int width )
{
	return length * width;
}

double CalculateAreaCir( int radius )
{
	return 3.14 * radius * radius;
}
