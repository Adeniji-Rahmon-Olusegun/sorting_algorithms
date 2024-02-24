#include "sort.h"

/**
 * swap_elements - swaps two (2) elements adjacent elements
 *
 * @e1: pointer to first element
 * @e2: pointer to second element
 *
 * Return: void
 */

void swap_elements(int *e1, int *e2)
{
	int temp_var;

	temp_var = *e1;
	*e1 = *e2;
	*e2 = temp_var;
}

/**
 * lomuto_partition - partitions an array
 *
 * @array: unsorted array
 * @low_bnd: lower bound
 * @up_bnd: upper bound
 *
 * Return: upper bound
 */

int lomuto_partition(int *array, int low_bnd, int up_bnd, size_t size)
{
	int jdx, start;
	int pivot;

	pivot = array[up_bnd];
	start = low_bnd - 1;

	for (jdx = low_bnd; jdx < up_bnd; jdx++)
	{
		if (array[jdx] < pivot)
		{
			start++;
			swap_elements(&array[start], &array[jdx]);
			/*print_array(array, size);*/
		}
	}
	
	swap_elements(&array[start + 1], &array[up_bnd]);

	print_array(array, size);

	return start + 1;
}

/**
 * recursive_sort - implements partition recursively
 *
 * @array: unsorted array
 * @low_bnd: lower bound
 * @up_bnd: upper bound
 *
 * Return: void
 */

void recursive_sort(int *array, int low_bnd, int up_bnd, size_t size)
{
	int location;

	if (low_bnd < up_bnd)
	{
		location = lomuto_partition(array, low_bnd, up_bnd, size);
		recursive_sort(array, low_bnd, location - 1, size);
		recursive_sort(array, location + 1, up_bnd, size);
	}
}

/**
 * quick_sort - sorts an unsorted array using
 * quick sort algorithm.
 *
 * @array: unsorted array
 * @size: length of array
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
	{
		return;
	}

	recursive_sort(array, 0, size - 1, size);
}
