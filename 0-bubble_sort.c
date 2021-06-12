#include "sort.h"

/**
 * swap - Swaps for sort
 * @var1: Variable 1
 * @var2: Variable 2
 * Return: Void
 */

void swap(int *var1, int *var2)
{
	int temp = *var1;

	*var1 = *var2;
	*var2 = temp;
}

/**
 * bubble_sort - Sorts Array
 * @array: Array
 * @size: Size
 * Return: Void
 *
 */

void bubble_sort(int *array, size_t size)
{
	unsigned int i = 0;
	unsigned int j = 0;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}

}

