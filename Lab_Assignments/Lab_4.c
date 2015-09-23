// Tyler Bourque; tbourque2012
/*Lab 4
Lab topic: Conditions –
Lecture topics this week: conditions / loops
// (calculates  different sales tax based on an item price)

1. Ask the user to enter the price of an item.
2. Get the item price from the user.
3. Calculate the sales tax of the item:
Use 6.5% if the item costs less than $150.
Use 6% if the item costs $150 or more.
4. Display the original item price and sales tax amount onto the screen.
5. Calculate new cost of the item with the sales tax.
6. Display the total price of the item onto the screen.*/

#include	<stdio.h>

#define		SMALL_TAX 0.065 //The sales Tax of an item that is less than $150
#define		LARGE_TAX 0.060 // The sales tax of an item that is more than %150

double getDouble( void );
double calculateTaxOfItem( double );
double totalCalculation( double , double );

	int main( )
{
	double itemPrice;
	double taxOfItem;
	double totalPrice;


	printf( "This program will find the tax of a certain item.\n" );
	printf( "Please type in a price of an item.\n" );

	itemPrice = getDouble( );

	taxOfItem = calculateTaxOfItem( itemPrice );

	totalPrice = totalCalculation( itemPrice , taxOfItem );

	printf( "The Item that is worth %6.2f will have a sales tax of %6.3f\n", itemPrice, taxOfItem );
	printf( "The Total Price for that Item will be:%6.2f\n", totalPrice );

	return 0;
}


//Function Definitions



double getDouble( void )
{
	double x;
	scanf( "%lf", &x );

	return x;
}

double calculateTaxOfItem( double itemPrice )
{
	double salesTax;
	if ( itemPrice < 150 )
	{
		salesTax = SMALL_TAX;		
	}
	else
	{
		salesTax = LARGE_TAX;
	}

	return salesTax;
}

double totalCalculation ( double itemPrice , double taxOfItem )
{
	return ( itemPrice * taxOfItem ) + itemPrice;
}