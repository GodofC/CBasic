#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define SIZE 10
/***********************************************************************************************************************
*PROTOTYPE
***********************************************************************************************************************/
int checkNumber(float row, float col);
int checkPositive(float row, float col);
int checkInteger(float row, float col);
int checkMultiply(float row1,float row2,float col1, float col2);
void matrixInput(float matrix[SIZE][SIZE], float row, float col);
void matrixOutput(float matrix[SIZE][SIZE], float row, float col);
void matMul(float mt1[SIZE][SIZE], float mt2[SIZE][SIZE], float mt3[SIZE][SIZE],float r1, float r2, float c1, float c2);
/***********************************************************************************************************************
*CODE
***********************************************************************************************************************/
int main()
{
	float matrix1[SIZE][SIZE], matrix2[SIZE][SIZE], matrix3[SIZE][SIZE];
	float row1, col1, row2, col2;
	char cont[5];

	printf("\n This program is able to work with matrix with the maximum SIZE: %d x %d", SIZE, SIZE);
	do
	{
		printf("\n *****************FIRST MATRIX********************");
		do
		{
			printf("\n Enter the first matrix's number of rows     \t");
			scanf("%f", &row1);
			printf("\n Enter the first matrix's number of columns  \t");
			scanf("%f", &col1);
		}
		while(checkNumber(row1, col1) != 1);

		printf("\n********* Enter the first matrix's data *********");
		matrixInput(matrix1, row1, col1);
		matrixOutput(matrix1, row1, col1);

		printf("\n *****************SECOND MATRIX*******************");
		do
		{
			printf("\n Enter the second matrix's number of rows    \t");
			scanf("%f", &row2);
			printf("\n Enter the second matrix's number of columns \t");
			scanf("%f", &col2);
		}
		while(checkNumber(row2, col2) != 1);

		printf("\n********* Enter the second matrix's data *********");
		matrixInput(matrix2, row2, col2);
		matrixOutput(matrix2, row2, col2);
		printf("\n**************************************************");

		switch(checkMultiply(row1, row2, col1, col2))
		{
			case 1:
			{
				printf("\n**** The multiply of the 1st and 2nd matrix ****");
				matMul(matrix1, matrix2, matrix3, row1, row2, col1, col2);
				matrixOutput(matrix3, row1, col2);
				printf("\n**** The multiply of the 2nd and 1st matrix ****");
				matMul(matrix2, matrix1, matrix3, row2, row1, col2, col1);
				matrixOutput(matrix3, row2, col1);
				break;
			}
			case 2:
			{
				printf("\n**** The multiply of the 1st and 2nd matrix ****");
				matMul(matrix1, matrix2, matrix3, row1, row2, col1, col2);
				matrixOutput(matrix3, row1, col2);
				break;
			}
			case 3:
			{
				printf("\n**** The multiply of the 2nd and 1st matrix ****");
				matMul(matrix2, matrix1, matrix3, row2, row1, col2, col1);
				matrixOutput(matrix3, row2, col1);
			}
			case 0:
			{
				printf("\n**** Your matrix can't be multipy together ****");
				break;
			}
		}
		printf("\n Do you want to try again ? (Yes/No)");
		fflush(stdin);
		gets(cont);
		if(strcmp(cont,"No") ==0)
		{
			break;
		}
	}
	while(1);


	return 0;
}
/*
*Function {int} checkNumber
*@Brief Check if the row and column number of the matrix is a positive Integer
		Notify user what to re-enter
*@Para  row: number of the matrix row
		col: number of the matrix col
*@Return status: = 1 if the input is a positive integer
				 = 0 if the input is not a positve integer
*/
int checkNumber(float row,float col)
{
	int status;
	if(checkPositive(row, col) == 1 && checkInteger(row, col) == 1)
	{
		status = 1;
	}
	else
	{
		status = 0;
	}
	switch(checkPositive(row, col))
	{
		case 2:
		{
			printf("\n Your column number is non positive");
			break;
		}
		case 3:
		{
			printf("\n Your row number is non positive");
			break;
		}
		case 0:
		{
			printf("\n Your row & column number is non positvie");
			break;
		}
	}
	switch(checkInteger(row, col))
	{
		case 2:
		{
			printf("\n Your column number is not an integer");
			break;
		}
		case 3:
		{
			printf("\n Your row number is not an integer");
			break;
		}
		case 0:
		{
			printf("\n Your column number & row number is not an integer");
			break;
		}
	}
	return status;
}
/*
*Function {int} checkPositive
*@Brief Check if the row and column number of the matrix is a positive number
*@Para  row: number of the matrix row
		col: number of the matrix col
*@Return status: = 0 if the matrix column and row is non positive
				 = 1 if the matrix column and row is positve
				 = 2 if the matrix column is non positive and row is positive
				 = 3 if the matrix column is positive and column is negative
*/
int checkPositive(float row, float col)
{
	int status;
	if(row > 0 && col > 0)
	{
		status = 1;
	}
	else if(row > 0)
	{
		status = 2;
	}
	else if(col > 0)
	{
		status = 3;
	}
	else
	{
		status = 0;
	}
	return status;
}
/*
*Function {int} checkInteger
*@Brief Check if the row and column number of the matrix is a integer number
*@Para  row: number of the matrix row
		col: number of the matrix col
*@Return status: = 0 if the matrix column and row is not an integer
				 = 1 if the matrix column and row is an integer
				 = 2 if the matrix column is an  row is positive
				 = 3 if the matrix column is positive and column is negative
*/
int checkInteger(float row, float col)
{
	int status;
	/* Decimal part = real part - integer part */
	if(row - (int)row == 0 && col - (int)col == 0)
	{
		status = 1;
	}
	else if(row - (int)row == 0)
	{
		status = 2;
	}
	else if(col - (int)col == 0)
	{
		status = 3;
	}
	else
	{
		status = 0;
	}
	return status;
}
/*
*Function {void} matrixInput
*@Brief User enter the matrix's cell
*@Para  matrix: matrix array need to fill in
		row:    number of the matrix row
		col:    number of the matrix col
*@Return [none]
*/
void matrixInput(float matrix[SIZE][SIZE], float row, float col)
{
	int i,j;
	for(i = 0; i < row; i ++)
	{
		for(j = 0; j < col; j ++)
		{
			printf("\n A[%d][%d] = ", i+1, j+1);
			scanf("%f", &matrix[i][j]);
		}
	}
}
/*
*Function {void} matrixOutput
*@Brief Print out the whole matrix
*@Para  matrix: matrix 2D array need to print out
		row:    number of the matrix row
		col:    number of the matrix col
*@Return [none]
*/
void matrixOutput(float matrix[SIZE][SIZE], float row, float col)
{
	int i,j;
	printf("\n");
	for(i = 0; i < row; i ++)
	{
		printf("|");
		for(j = 0; j < col; j ++)
		{
			printf("\t");
			printf("%4.4f",matrix[i][j]);
		}
		printf("\t   |\n");
	}
}
/*
*Function {int} checkMultiply
*@Brief check if 2 matrix can be multiply together or not
*@Para  row1:    number of the 1st matrix's row
		row2:    number of the 2nd matrix's row
		col1:    number of the 1st matrix's column
		col2:    number of the 2nd matrix's column
*@Return status = 0     two matrix can't be multiply together
		 status = 1     first matrix can be multiply with the second matrix
		 status = 2     second matrix can be multiply with the first matrix
*/
int checkMultiply(float row1, float row2, float col1, float col2)
{
	int status;
	if(row1 == row2 && col1 == col2)
	{
		status = 1;
	}
	else if(row2 == col1)
	{
		status = 2;
	}
	else if(row1 == col2)
	{
		status = 3;
	}
	else
	{
		status = 0;
	}
	return status;
}
/*
*Function {void} matMul
*@Brief multiply the first matrix with the second matrix
*@Para  mt1    first matrix 2D array
		mt2    second matrix 2D array
		mt3    result matrix 2D array
		r1:    number of the 1st matrix's row
		r2:    number of the 2nd matrix's row
		c1:    number of the 1st matrix's column
		c2:    number of the 2nd matrix's column
*@Return [none]
*/
void matMul(float mt1[SIZE][SIZE], float mt2[SIZE][SIZE], float mt3[SIZE][SIZE], float r1, float r2, float c1, float c2)
{
	int i,j,k;
	for(i = 0; i < r1; i ++)
	{
		for(j = 0; j < c2; j ++)
		{
			mt3[i][j] = 0;
			for(k = 0;k < c1; k ++)
			{
				mt3[i][j] += mt1[i][k] * mt2[k][j];
			}
		}
	}
}
