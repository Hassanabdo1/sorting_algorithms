#include "sort.h"

/**
 * swap_ints - Function that swaps two integers in an array.
 * @a: Is the first integer to swap.
 * @b: Is the second integer to swap.
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
 * bubble_sort - helps sort an array of integers in ascending order
 * @array: This is an array of integers to sort.
 * @size: represents the size of the array.
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

