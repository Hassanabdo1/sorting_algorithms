#include "sort.h"

/**
 * Swap_ints: This function helps to swap two individuals in an array
 * @a:Is a pointer variable reperesnting the first integer to print.
 * @b:Is a pointer variable reperenting the second integer to print.
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
 * bubble_sort: Is a function that sort an array of integers
 * @array: This represent an array of integers for sorting.
 * @size: This represents the size of the array.
 *
 * Description: this prints the array after each swap.
 */

void bubble_sort(int *array, size_t size);
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}

