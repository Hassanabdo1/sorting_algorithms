#include "sort.h"

/**
 * swap_ints - This func swap two integers in an array.
 * @a: This is the first integer to swap.
 * @b: This is the second integer to swap.
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
 * shell_sort - This func helps sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: This rep an array of integers.
 * @size: This rep the size of the array.
 *
 * Description: It uses the Knuth interval sequence.
 */

void shell_sort(int *array, size_t size);
void shell_sort(int *array, size_t size)
{
	size_t gap;
	size_t i;
	size_t j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_ints(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
