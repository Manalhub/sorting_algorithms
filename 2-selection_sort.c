#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, minval;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		minval = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minval])
				minval = j;
		}

		if (minval != i)
		{
			temp = array[i];
			array[i] = array[minval];
			array[minval] = temp;
			print_array(array, size);
		}
	}
}
