#include "sort.h"

/**
 * swap_sel - Swaps for sort
 * @var1: Variable 1
 * @var2: Variable 2
 * Return: Void
 */

void swap_sel(int *var1, int *var2)
{
	int temp = *var1;

	*var1 = *var2;
	*var2 = temp;
}

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

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		index = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[index])
				index = j;
		if (i != index)
		{
			swap_sel(&array[index], &array[i]);
			print_array(array, size);
		}
	}
}
