/***********************************************************************************************************************
 *Author: HieuPM
 *Date Modifed: 23/06/2017 9h20
 *Name: HieuPM_CBasic_ass4.1
 **********************************************************************************************************************/
This program help you multiply 2 matrix and entered by the user and print the result to the screen!
/Function1*************************************************************************************************************/
/*
*Function {int} checkNumber
*@Brief Check if the row and column number of the matrix is a positive Integer
		Notify user what to re-enter
*@Para  row: number of the matrix row
		col: number of the matrix col
*@Return status: = 1 if the input is a positive integer
				 = 0 if the input is not a positve integer
*/
/Function2*************************************************************************************************************/
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
/Function3*************************************************************************************************************/
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
/Function4*************************************************************************************************************/
/*
*Function {void} matrixInput
*@Brief User enter the matrix's cell
*@Para  matrix: matrix array need to fill in
		row:    number of the matrix row
		col:    number of the matrix col
*@Return [none]
*/
/Function5*************************************************************************************************************/
/*
*Function {void} matrixOutput
*@Brief Print out the whole matrix
*@Para  matrix: matrix 2D array need to print out
		row:    number of the matrix row
		col:    number of the matrix col
*@Return [none]
*/
/Function6*************************************************************************************************************/
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
/Function7*************************************************************************************************************/
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