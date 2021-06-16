#include "sort.h"

/**
 * counting_sort - Sorts Array
 * @array: Array
 * @size: Size
 * Return: Void
 */

void counting_sort(int *array, size_t size)
{
	int i = 0;
	int max = 0;
	int *result = NULL;
	int *count = NULL;

	if (array == NULL || size < 2)
		return;
	result = malloc(sizeof(int) * size);
	if (result == NULL)
		return;
	for (; i < (int)size; i++)
	{
		result[i] = array[i];
		if (array[i] > max)
			max = array[i];
	}
	count = malloc(sizeof(int) * max + 1);
	if (count == NULL)
	{
		free(result);
		return;
	}
	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		++count[array[i]];
	for (i = 0; i <= max; i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);
	for (i = 0; i < (int)size; i++)
	{
		result[count[array[i]] - 1] = array[i];
		--count[array[i]];
	}
	for (i = 0; i < (int)size; i++)
		array[i] = result[i];
	free(result);
	free(count);
}
