#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - This function swap two integers in an array.
 * @a: rep the first integer to swap.
 * @b: rep is the second integer to swap.
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
 * max_heapify - func that turns a binary tree into a complete binary 
 * heap.
 * @array: rep an array of integers representing a binary tree.
 * @size: rep the size of the array/tree.
 * @base: rep the index of the base row of the tree.
 * @root: rep the root node of the binary tree.
 */

void max_heapify(int *array, size_t size, size_t base, size_t root);
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left;
	size_t right;
	size_t large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_ints(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - This function sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @size: rep the size of the array.
 * @array: rep an array of integers.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */

void heap_sort(int *array, size_t size);
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_ints(array, array + i);
		print_array(array, size);
		max_heapify(array, size, i, 0);
	}
}
