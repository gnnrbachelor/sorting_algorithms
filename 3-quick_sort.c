#include "sort.h"

/**
 * swap_q - Swaps for sort
 * @var1: Variable 1
 * @var2: Variable 2
 * Return: Void
 */

void swap_q(int *var1, int *var2)
{
	int temp = *var1;

	*var1 = *var2;
	*var2 = temp;
}

/**
 * partition - Creates partition for quicksort
 * @array: Array
 * @low: Low
 * @high: High
 * @size: Size
 * Return: size_t
 *
 */

size_t partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t i;
	ssize_t j;
	int pivot;

	pivot = array[high];
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap_q(&array[i], &array[j]);
			print_array(array, size);
		}
	}

	swap_q(&array[i + 1], &array[high]);
	print_array(array, size);

	return (i + 1);
}

/**
 * rec_sort - Implements recursion
 * @array: Array
 * @low: Beginning
 * @high: End
 * @size: Size
 */

void rec_sort(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t pivot = 0;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		rec_sort(array, low, pivot - 1, size);
		rec_sort(array, pivot + 1, high, size);
	}
}



/**
 * quick_sort - Sorts array
 * @array: Address of array
 * @size: Size
 * Return: Void
 */

void quick_sort(int *array, size_t size)
{

	if (array == NULL || size < 2)
		return;
	rec_sort(array, 0, size - 1, size);
}

