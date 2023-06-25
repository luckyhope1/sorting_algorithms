#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * prints the array after each time you swap two elements
 *
 * @array: array of integers to be sorted
 * @size: number of integers in array
 */

void bubble_sort(int *array, size_t size)
{
	int swapped;
	size_t i, j;

	for (i = 0; i < size - 1; ++i)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; ++j)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];

				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
			}
		}
		if (!swapped)
		{
			break;
		}
	}
}
