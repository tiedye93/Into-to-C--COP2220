//Tyler Bourque; tbourque2012
//Lab 10
/* Lab topic: User-defined structs – 
Lecture topics: user-defined structs.
  
- Change the struct card from the attached file to struct auto with the following fields:
char array for make
char array for model
int for the year
double  dealer cost
double price
 Modify all variable declarations, function prototypes, and functions calls to reflect the changes from card to auto */

#define _CRT_SECURE_NO_DEPRECATE

#include <string.h>
#include <stdio.h>
#define SIZE 20

typedef struct
{

 char make[SIZE];
 char model[SIZE];
 int year;
 double dealer_cost;
 double price;

}vehicle;

//Function Prototypes

vehicle Fillvehicle();
void FillvehiclePtr(vehicle *vehicleptr);
void FillvehicleArray(vehicle arrayC[], int *size);
void Displayvehicle(vehicle anyvehicle);

int main()
{


	vehicle myvehicle, myvehicle_1, myvehicle_2;
	vehicle manyvehicles[SIZE];
	int vSize;
	int i;

	myvehicle = Fillvehicle();
	myvehicle_1 = Fillvehicle();

	printf("\n---------Display myvehicle\n");
	Displayvehicle(myvehicle);
	printf("\n---------Display myvehicle_1\n");
	Displayvehicle(myvehicle_1);

	FillvehiclePtr(&myvehicle_2);
	printf("\n---------Display myvehicle_2\n");
	Displayvehicle(myvehicle_2);

	printf("\n---------Fill array manyvehicles\n");
	FillvehicleArray(manyvehicles, &vSize);

	printf("\n---------Display array manyvehicles\n");
	for(i=0;i<vSize; i++)
	{
		Displayvehicle(manyvehicles[i]);
	}

	return 0;
}

//Function Definitions


vehicle Fillvehicle()
{

	vehicle tempV;

	printf("\nplease enter the make of your vehicle:  ");
	scanf("%s", tempV.make);
	printf("make:  %s\n", tempV.make);

	printf("\nplease enter the model of your vehicle:  ");
	scanf("%s", tempV.model);
	printf("model:  %s\n", tempV.model);

	printf("\nplease enter the year of your vehicle:  ");
	scanf("%d", &tempV.year);
	printf("year:  %d\n", tempV.year);

	printf( "\nplease enter the dealer cost of your vehicle: " );
	scanf( "%lf", &tempV.dealer_cost );
	printf( "dealer cost:  %f\n", tempV.dealer_cost );

	printf( "\nplease enter the price of your vehicle: " );
	scanf( "%lf", &tempV.price );
	printf( "price:  %f\n", tempV.price );


	return tempV;
}



void Displayvehicle(vehicle anyvehicle)
{
	printf("\n\nmake:  %s\n", anyvehicle.make);
	printf("model:  %s\n", anyvehicle.model);
	printf("year:  %d\n", anyvehicle.year);
	printf( "dealer cost:  %f\n", anyvehicle.dealer_cost );
	printf( "price:  %f\n", anyvehicle.price );
}


void FillvehiclePtr(vehicle *vehicleptr)
{
	printf("\nplease enter the make of your vehicle:  ");
	scanf("%s", (*vehicleptr).make);

	printf("\nplease enter the model of your vehicle:  ");
	scanf("%s", vehicleptr->model);

	printf("\nplease enter the year of your vehicle:  ");
	scanf("%d", &(*vehicleptr).year);

	printf("\nplease enter the dealer cost of your vehicle:  ");
	scanf("%lf", &(*vehicleptr).dealer_cost);

	printf("\nplease enter the price of your vehicle:  ");
	scanf("%lf", &(*vehicleptr).price);
}





void FillvehicleArray(vehicle arrayC[], int *size)
{
	int i;

	printf("\nenter the number of vehicles:  ");
	scanf("%d", size);


	printf("size:  %d\n", *size);

	for (i=0; i < *size; i++)
	{
		printf("enter make:  ");
		scanf("%s", arrayC[i].make);

		printf("enter model:  ");
		scanf("%s", arrayC[i].model);

		printf("enter year:  ");
		scanf("%d", &arrayC[i].year);

		printf("enter dealer cost:  ");
		scanf("%lf", &arrayC[i].dealer_cost);

		printf("enter price:  ");
		scanf("%lf", &arrayC[i].price);
	}
}





