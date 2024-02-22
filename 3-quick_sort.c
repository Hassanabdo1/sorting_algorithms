#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * @a: Is the first integer to swap.
 * @b: Is the second integer to swap.
 * swap_ints - This swap two integers in an array
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
 * lomuto_partition - This orders a subset of an array of integers
 * 					 according to The lomuto partition scheme
 * 					 (last element as pivot).
 * @array: This is the array of integers.
 * @size: Represents the size of the array.
 * @left: Represents the starting index of the subset to order.
 * @right: Represents the ending index of the subset to order.
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
 * lomuto_sort - It Implement the quicksort algorithm through recursion.
 * @left: Represents the starting index of the array partition to order.
 * @right: Represents The ending index of the array partition to order.
 * @array: Represents an array of integers to sort.
 * @size: Represents the size of the array.
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
 * quick_sort - Helps sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @size: Represents the size of the array.
 * @array: Represents an array of integers.
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
