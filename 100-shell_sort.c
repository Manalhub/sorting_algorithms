#include "sort.h"

/**
 * shell_sort - Sorts an array of integers using the Shell Sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 */
void shell_sort(int *array, size_t size)
{
	int temp;
	size_t i, j;
	size_t interval = 1;

	if (array == NULL || size < 2)
		return;

	while (interval <= size / 3)
	{
		interval = interval * 3 + 1;
	}


	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}

			array[j] = temp;
		}

		print_array(array, size);

		interval = (interval - 1) / 3;
	}
}
