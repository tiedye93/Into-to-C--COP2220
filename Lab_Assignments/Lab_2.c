/* Author: Tyler Bourque; ttbourque2012
Lab topic: Interactive program –
Lecture topics this week: user-defined functions and introduction to conditions
Create a small program based on the following 
(calculate area of a circle and a rectangle):
//use integers for the length, width, areaRec, and radius,
//use double for areaCir
1. Declare variables: length, width, areaRec, radius, and areaCir.
2. Ask the user to enter the length and width of the rectangle and the radius of the circle. 
3. Get the length, width, and radius from the user.
4. Calculate the area of the rectangle.
5. Display the length, width, and area of the rectangle onto the screen.
6. Calculate the area of the circle (use 3.14).
7. Display the radius and area of the circle onto the screen.*/

#include	<stdio.h>


int main( )
{
	int length, width, areaRec, radius;
	double areaCir;

	printf( "This program will calculate the area of a Rectangle & a Circle\n" );
	printf( "Please type in the length and width for a rectangle:" );
	scanf( "%d %d", &length, &width );
	areaRec = length * width;
	printf( "Please type in the Radius of a Circle:" );
	scanf( "%d", &radius );
	areaCir = 2 * 3.14 * radius;
	printf( "The rectangle with the length being %d and the width being %d will have an area of %d.\n", length, width, areaRec );
	printf( "The area of a Circle with the radius of %d is %lf.\n", radius, areaCir );
		
	return 0;

}
