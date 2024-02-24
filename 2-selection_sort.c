#include "sort.h"

/**
 * swap_ints - This is a function that swaps two integers in an array.
 * @a: rep the first integer to swap.
 * @b: rep the second integer to swap.
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
 * selection_sort - This func sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: This represents an array of integers.
 * @size: Thiis represents the size of the array.
 *
 * Description: This prints the array after each swap.
 */

void selection_sort(int *array, size_t size);
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i;
	size_t j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
