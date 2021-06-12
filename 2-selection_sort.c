#include "sort.h"

/**
 * selection_sort - Sorts array
 * @array: Array
 * @size: Size
 * Return: Void
 */

void selection_sort(int *array, size_t size)
{
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int index = 0;

	for (i = 0; i < size - 1; i++)
	{
		index = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[index])
				index = j;

		swap(&array[index], &array[i]);
		print_array(array, size);
	}
}
