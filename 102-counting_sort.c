#include "sort.h"

/**
 * find_max_val - finds the maximum value
 * in an array
 *
 * @array: array of integers
 * @size: length of array
 *
 * Return: maximum value
 */

int find_max_val(int *array, size_t size)
{
	size_t idx;
	int max_value;

	max_value = array[0];

	for (idx = 1; idx < size; idx++)
	{
		if (array[idx] > max_value)
		{
			max_value = array[idx];
		}
	}

	return (max_value);
}

/**
 * free_null - frees memory not properly
 * allocated
 *
 * @pointer_mem: points to the dynamically
 * allocated memory block
 */

void free_null(int *pointer_mem)
{
	if (pointer_mem == NULL)
	{
		free(pointer_mem);

		return;
	}
}

/**
 * counting_sort - sorts an unsorted array using
 * counting_sort algorithm
 *
 * @array: unsorted array
 * @size: length of an array
 *
 * Return - viod
 */


void counting_sort(int *array, size_t size)
{
	int jdx, max_k;
	size_t idx;
	int *count_array, *array_copy;

	if (!array || size < 2)
		return;

	max_k = find_max_val(array, size);

	count_array = (int *)malloc(sizeof(int) * (max_k + 1));
	free_null(count_array);

	array_copy = (int *)malloc(sizeof(int) * (size));
	free_null(array_copy);

	for (jdx = 0; jdx < (max_k + 1); jdx++)
		count_array[jdx] = 0;

	for (idx = 0; idx < size; idx++)
		count_array[array[idx]]++;

	for (jdx = 1; jdx <= max_k; jdx++)
		count_array[jdx] = count_array[jdx] + count_array[jdx - 1];

	print_array(count_array, max_k + 1);

	for (jdx = size - 1; jdx >= 0; jdx--)
		array_copy[--count_array[array[jdx]]] = array[jdx];

	for (idx = 0; idx < size; idx++)
		array[idx] = array_copy[idx];

	free(count_array);
	free(array_copy);
}
