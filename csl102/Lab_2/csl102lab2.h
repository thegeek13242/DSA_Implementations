/**
 * The header file must be in the same folder/directory as your C file when you
implement. DO NOT submit the header file. DO NOT change this header file
**/

/**
 * In this exercise, you find the second largest and second smallest element.
 * The function must return the difference between second largest and second smallest.
 * For example, in the array [21, 7, 6, 13, 56, 2, 8, 99], 
 * 56 is the second largest element and 7 is the second smallest element. 
 * Thus, the function must return 56 - 7 = 49.
 * You can reuse the code @ https://github.com/aniket-acad/csl102_ds_iiitn.
 * arr = starting address of the array. 
 * sz = number of elements in the array. Assume sz will be greater than 4.
 * */
int csl102_diff_2smallest_2biggest(int *arr, unsigned short sz);

/**
 * In this exercise you will find if the input array is in a sorted order
 * arr = starting address of the array.
 * If the array is not sorted, return 0
 * If the array is sorted in ascending order, return 1
 * If the array is sorted in descending order, return 2
 * */
unsigned short csl102_is_array_sorted(int arr[], unsigned short sz);

/**
 * In this exercise you will find if the input array has duplicate elements
 * Assume maximum one duplicate value
 * For example, in the array [21, 7, 99, 13, 56, 2, 8, 99], 99 is duplicate
 * arr = starting address of the array (has positive values only).
 * If the array has duplicate return the value/element (99 in the example)
 * If the array does not have duplicate return -1.
 * */
int csl102_find_duplicate(int arr[], unsigned short sz);