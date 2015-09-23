#include	<stdio.h> 	/*Author Tyler Bourque*/

int main( )
{
	int x=0;
	char letter;
	
	printf( "Hello! My name is Tyler Bourque\n" );
	printf( "Please type in a number: " );
	scanf( "%d", &x  );
	printf( "x= %d\n", x );
	printf( "x+10= %d\n", x+10 );

	printf( "please type in a letter: " );
	scanf( " %c", &letter );
	printf( "Your letter is : %c\n", letter );
	printf( "Thank you for your Cooperation!\n" );

	return 0;
}
	
