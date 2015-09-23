									/*Intro to Programming in C; Assignment #1*/
									/*Author: Tyler Bourque; tbourque2012*/
#include	<stdio.h>


int main( )
{

	double temp;	/* Temp used as the variable; Double used if user uses a number with decimals*/

	printf( "Greetings.\nThis program will take any temperature in Fahrenheit\nand convert it to Celsius.\n" ); /*Added '/n' to make it easier to read the program*/
	printf( "Type in a temperature in Fahrenheit:" );
	scanf( "%lf", &temp );
	printf( "%f degrees in Fahrenheit is %f degrees in Celsius.\n", temp, ( temp - 32 ) / ( 9 / 5. )); /*Formula for the conversion from Fahrenheit to Celsius is temperature minus 32, then multiply by 9/5; the '.' is added to make sure it stays in type double*/
	printf( "Thank you for using this program to help convert temperatures.\nHave a wonderful day.\n" );

	return 0;
}

