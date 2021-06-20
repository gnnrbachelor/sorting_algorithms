#include "sort.h"

/**
 * merge - Final merge
 * @beg: Beginning
 * @mid: Middle
 * @end: End
 * @array: Array
 * @buffer: Buffer
 * Return: Void
 */

void merge(size_t beg, size_t mid, size_t end, int *array, int *buffer)
{
	size_t i = beg;
	size_t j = mid;
	size_t k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(buffer + beg, mid - beg);
	printf("[right]: ");
	print_array(buffer + mid, end - mid);

	for (k = beg; k < end; k++)
	{
		if (i < mid && (j >= end || buffer[i] <= buffer[j]))
		{
			array[k] = buffer[i];
			i++;
		}
		else
		{
			array[k] = buffer[j];
			j++;
		}
	}

	for (mid = beg; mid < end; mid++)
		buffer[mid] = array[mid];


	printf("[Done]: ");
	print_array(array + beg, end - beg);
}

/**
 * split_merge - Merges split arrays
 * @beg: Beginning
 * @end: End
 * @array: Array
 * @buffer: Buffer
 * Return: Void
 */

void split_merge(size_t beg, size_t end, int *array, int *buffer)
{
	size_t mid = 0;

	if (end - beg < 2)
		return;

	mid = (beg + end) / 2;
	split_merge(beg, mid, array, buffer);
	split_merge(mid, end, array, buffer);
	merge(beg, mid, end, array, buffer);
	for (mid = beg; mid < end; mid++)
	{
		buffer[mid] = array[mid];
	}
}

/**
 * merge_sort - Sorts Array
 * @array: Array
 * @size: Size
 * Return: Void
 *
 */

void merge_sort(int *array, size_t size)
{
	size_t i = 0;
	int *buffer = NULL;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	for (i = 0; i < size; i++)
		buffer[i] = array[i];

	split_merge(0, size, array, buffer);
	free(buffer);
}


