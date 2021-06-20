#include "sort.h"

/**
 * swap_h - Swaps two ints
 * @var1: Var 1
 * @var2: Var 2
 * Return: Void
 */

void swap_h(int *var1, int *var2)
{
	int temp = *var1;

	*var1 = *var2;
	*var2 = temp;
}

/**
 * heapify - Creates Heap
 * @array: Array
 * @size: Size
 *
 *
 */

void heapify(int *array, size_t size, size_t level, size_t i)
{
	size_t l = 0;
	size_t r = 0;
	size_t largest = i;

	l = 2 * i + 1;
	r = 2 * i + 2;

	if (l < level && array[l] > array[largest])
		largest = l;

	if (r < level && array[r] > array[largest])
		largest = r;

	if (largest != i)
	{
		swap_h(&array[i], &array[largest]);
		print_array(array, size);
		heapify(array, size, level, largest);
	}
}


/**
 * heap_sort - Sorts Array
 * @array: Array
 * @size: Size
 * Return: Void
 */

void heap_sort(int *array, size_t size)
{

	int i = 0;

	if (array == NULL || size < 2)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_h(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, size, i, 0);
	}


}
