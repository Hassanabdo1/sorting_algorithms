#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sorts_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - This func helps sort a subarray of integers.
 * @subarr: This rep a subarray of an array of integers to sort.
 * @buff: This rep a buffer to store the sorted subarray.
 * @front: This rep the front index of the array.
 * @mid: This rep the middle index of the array.
 * @back: This rep the back index of the array.
 */

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		buff[k++] = subarr[i];
	for (; j < back; j++)
		buff[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sorts_recursive - Func that helps implement the merge sort 
 * 						algorithm through recursion.
 * @subarr: rep a subarray of an array of integers to sort.
 * @buff: rep a buffer to store the sorted result.
 * @front: rep the front index of the subarray.
 * @back: rep back index of the subarray.
 */

void merge_sorts_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sorts_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sorts_recursive(subarr, buff, front, mid);
		merge_sorts_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - A function that sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: rep an array of integers.
 * @size: rep the size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sorts_recursive(array, buff, 0, size);

	free(buff);
}
