#include "sort.h"

/**
 * swap_num - Swaps for sort
 * @var1: Variable 1
 * @var2: Variable 2
 * Return: Void
 */

void swap_num(int *var1, int *var2)
{
	int temp = *var1;

	*var1 = *var2;
	*var2 = temp;
}

/**
 * shell_sort - Sorts array
 * @array: Array
 * @size: Size
 * Return: Void
 */


void shell_sort(int *array, size_t size)
{
	size_t interval = 1;
	size_t i = 0;
	size_t j = 0;

	if (array == NULL || size < 2)
		return;

	while (interval < size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			for (j = i; j >= interval && array[j - interval] > array[j]; j -= interval)
				swap_num(array + j, array + (j - interval));
		}
		interval = (interval - 1) / 3;
		print_array(array, size);
	}
}
