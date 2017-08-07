#include <stdio.h>
#include <stdint.h>
#include <math.h>
/***********************************************************************************************************************
Prototype
***********************************************************************************************************************/
int Solve(float a, float b, float c);
int Side(float diag, float peri);
int Negative(float diag, float peri);
/***********************************************************************************************************************
Code Input a diagonal and perimeter of an rectangle check if it is a rectangle and find it's area 
***********************************************************************************************************************/
int main()
{
	float diag, peri;
	do
	{
	printf("\n Enter your rectangle diagonal ");
	scanf("%f",&diag);
	printf("\n Enter your rectangle perimeter ");
	scanf("%f",&peri);
	}
	while((Negative(diag,peri) == 1) || (Side(diag,peri) == 1));
	
	
	return 0;
}
/*
Function : int Side(float diag, float peri)
	@brief: Find the side of the rectangle if posible
				+ diag: diagonal of the rectangle
				+ perimeter of the rectangle
	@return: 
				+ 0 - the input valid
				+ 1 - the input invalid
*/
int Side(float diag, float peri)
{   
	float area;
	int status;
	area = (peri * peri - 4 * diag * diag) / 8;
	if(area >0 || peri > 0)
	{
		if(Solve(1,- peri / 2,area)==0)
		{
			status = 0;
		}
	}
	else
	{
		status = 1;
	}
	return status;
}
/*
Function : int Solve(float a,float b,float c)
	@brief: Solve the quardatic function
				+ float a - a parameter
				+ float b - b parameter
				+ float c - c parameter
	@return: 
				+ 0 - the input valid need further check
				+ 1 - the input invalid
*/
int Solve(float a, float b, float c)
{
	float delta, x1, x2;
	int status;

	if (a == 0)
	{
		printf("\n Input invalid - Not a rectangle");
		status = 1;
	}
	else
	{
		delta = b * b - 4 * a * c ;
		if (delta < 0)
		{
			printf("\n Input invalid - Not a rectangle");
			status = 1;
		}
		if (delta == 0)
		{
			x1 = x2 = - b / (2 * a);
			if(x1 > 0 && x2 > 0)
			{
				printf("\n Input valid");
				printf("\n Your rectangle area is %.2f",x1 * x2);
				status = 0;
				
			}
			else
			{
				printf("\n Input invalid - Not a rectangle");
				status = 1;
			}

		}
		if (delta > 0)
		{
			x1=(- b + sqrt(delta)) / (2 * a);
			x2=(- b - sqrt(delta)) / (2 * a);

			if(x1 > 0 && x2 > 0)
			{
				printf("\n Input valid");
				printf("\n Your rectangle area is %.2f",x1 * x2);
				status = 0;
				
			}
			else
			{
				printf("\n Input invalid - Not a rectangle");
				status = 1;
			}

		}
	}
return status;
}
/*
Function : int Negative(float diag,float peri)
	@brief: Check if user enter a negative or decimal number
				+ float diag - diagonal of the rectangle
				+ float peri - perimeter of the rectangle
	@return: 
				+ 0 - the input valid need further check
				+ 1 - the input invalid
*/
int Negative(float diag, float peri)
{
	int status;
	if(diag <= 0 && peri <= 0)
	{
		printf("\n Your diagonal and perimeter value is non positve");
		status = 1;
	}
	else if (diag <= 0)
	{
		printf("\n Your diagonal value is is non positive");
		status = 1;
	}
	else if (peri <= 0)
	{
		printf("\n Your perimeter value is is non positive");
		status = 1;
	}
	else
	{
		status = 0;
	}
	return status; 
}