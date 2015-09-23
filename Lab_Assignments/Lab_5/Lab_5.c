//Tyler Bourque; tbourque2012

//LAB 5

/*Lab topic: File Processing – 
Lecture topics this week: Exam 1, and loops.
Create a file called numInput.txt and put some integers in the file.
Save the file in the same directory as your source code in your project.
Create an interactive program that reads an int from the file called numInput.txt, performs a 
calculation, and stores the result in a different file called resOut.txt.
1. Ask the user for a double.
2. Open a file called numInput.txt, and use fscanf to read an int from this file.
3. Multiply the double entered by the user by the int from the file, and store the result in a 
double.
4. Open a file called resOut.txt.
5. Use fprintf to write the result of the multiplication to the file resOut.txt. */



#include	<stdio.h>

double getNum( void );

int main( )
{
	double Num;
	int fromFile;
	double newNum;


	FILE *numInput, *resOut;

	
	numInput = fopen( "numInput.txt", "w");
	fprintf( numInput, "%d", 16);
	
	fclose( numInput );

	numInput = fopen( "numInput.txt", "r");
	if( numInput == NULL)
	{
		printf( "Could not find the File...\n" );

		return 1;
	}

	while( fscanf( numInput, "%d", &fromFile ) != EOF );
	{
		printf( "I just pulled a number from a file.\n" );
		printf( "I will take this number and multiply it by a number you will put in.\n" );
	}

	fclose( numInput );

	
	Num = getNum( );

	newNum = Num * fromFile;

	resOut = fopen( "resOut.txt", "w");
	fprintf( resOut, "%7.2f", newNum );

	fclose( resOut );

	return 0;
}


double getNum( void )
{
	double num;
	
	printf( "Please type in a number. Decimal numbers are allowed.\n" );
	scanf( "%lf", &num );

	return num;
}