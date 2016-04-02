/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
void spiral_wrapper(int rows, int columns, int **input_array, int *resultant, int x, int y, int r_start, int c_start, int state);
int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL || rows <= 0 || columns <= 0)
		return NULL;
	int *resultant, *address, x = 0, y = 0, r_start = 0, c_start = 0, state = 1;
	resultant = (int *)malloc((rows*columns)*sizeof(int));
	address = resultant;
	spiral_wrapper(rows, columns, input_array, resultant, x, y, r_start, c_start, state);
	return address;

}

void spiral_wrapper(int rows, int columns, int **input_array, int *resultant, int x, int y, int r_start, int c_start, int state)
{
	if (r_start < rows&&c_start < columns)
	{
		*resultant = *(*(input_array + x) + y);

	pos1:
		if (state == 1)
		{

			if (y + 1 == columns)
			{
				state = 2;
				rows = rows - 1;
			}
			else
				return spiral_wrapper(rows, columns, input_array, resultant + 1, x, y + 1, r_start, c_start, state);
		}
		if (state == 2)
		{
			if (x == rows)
			{
				state = 3;
				c_start = c_start + 1;
			}
			else
				return spiral_wrapper(rows, columns, input_array, resultant + 1, x + 1, y, r_start, c_start, state);
		}
		if (state == 3)
		{
			if (y + 1 == c_start)
			{
				state = 4;
				r_start = r_start + 1;
			}
			else
				return spiral_wrapper(rows, columns, input_array, resultant + 1, x, y - 1, r_start, c_start, state);
		}
		if (state == 4)
		{

			if (x == r_start)
			{
				state = 1;
				columns = columns - 1;
				goto pos1;
			}
			else
				return spiral_wrapper(rows, columns, input_array, resultant + 1, x - 1, y, r_start, c_start, state);
		}
	}
}
