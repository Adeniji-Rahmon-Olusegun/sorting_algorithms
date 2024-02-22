#include "sort.h"

/**
 * selection_sort - sorts an unsorted array using
 * selection sort algoritm
 *
 * @array: unsorted array
 * @size: length of array
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t idx, jdx, min_idx, temp_var;

	for (idx = 0; idx < size - 1; idx++)
	{
		min_idx = idx;

		for (jdx = idx + 1; jdx < size; jdx++)
		{
			if (array[jdx] < array[min_idx])
			{
				min_idx = jdx;
			}
		}

		if (min_idx != idx)
		{
			temp_var = array[idx];
			array[idx] = array[min_idx];
			array[min_idx] = temp_var;

			print_array(array, size);
		}
	}
}
