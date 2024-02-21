#include "sort.h"

/**
 * bubble_sort - sorts an unsorted array using
 * buble sort algorithm
 *
 * @array: unsorted array
 * @size: length of the array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t idx, jdex, flag, temp;

	for (idx = 0; idx < size - 1; idx++)
	{
		flag = 0;

		for (jdex = 0; jdex < size - 1 - idx; jdex++)
		{
			if (array[jdex] > array[jdex + 1])
			{
				temp = array[jdex];
				array[jdex] = array[jdex + 1];
				array[jdex + 1] = temp;

				print_array(array, size);

				flag = 1;
			}
		}

		if (flag == 0)
			break;
	}
}
