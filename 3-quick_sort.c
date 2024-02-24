#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * @a: This is the first integer to swap.
 * @b: This is the second integer to swap.
 * swap_ints - This helps to swap two integers in an array
 */

void swap_ints(int *a, int *b);
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - This func orders a subset of an array of integers
 * 					 according to The lomuto partition scheme
 * 					 (last element as pivot).
 * @array: This represents the array of integers.
 * @size: This represents the size of the array.
 * @left: This represents the starting index of the subset to order.
 * @right: This represents the ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot;
	int above;
	int below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Helps implement the quicksort algorithm through recursion.
 * @left: This rep the starting index of the array partition to order.
 * @right: This rep the ending index of the array partition to order.
 * @array: This represents an array of integers to sort.
 * @size: This represents the size of the array.
 * Description: Uses the Lomuto partition scheme.
 */

void lomuto_sort(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Is a func that helps sort an array of integers in 
 * 				ascending order using the quicksort algorithm.
 * @size: This represents the size of the array.
 * @array: This represents an array of integers.
 * Description: This uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */

void quick_sort(int *array, size_t size);
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
