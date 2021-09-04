/**
 * The header file must be in the same folder/directory as your C file when you
implement. DO NOT submit the header file. DO NOT change this header file
**/

/**
 * This function will fill the value in the 2d array. The array is allocated
 * memory on the heap in the main function. No need to allocated memoey in this function.
 * totalRows = total number of rows
 * totalColumns = total number of columns
 * seed = a small initial value, e.g., somewhere between 2 and 9.
 **/
void csl102_lab1_populate(int* array,int totalRows,int totalColumns, unsigned short seed);

/**
 * This function retrieves the value located at a given combination of row and column 
 * currentRow = the row number of interest
 * currentColumn = the column number of interest
 * totalColumns = total number of columns  
 **/
int csl102_lab1_get(int *array,int currentRow, int currentColumn,int totalColumns);

/**
 * This function will replace those elements of the 2d array that are ZERO 
 * in value with ONE
 * totalRows = total number of rows
 * totalColumns = total number of columns 
 **/
void csl102_lab1_replace_zeros(int* array,int totalRows,int totalColumns);

/**
 * This function returns the product (multiplication) of all values in the 2D array
 * totalRows = total number of rows
 * totalColumns = total number of columns 
 **/
unsigned long csl102_lab1_product(int* array,int totalRows,int totalColumns);