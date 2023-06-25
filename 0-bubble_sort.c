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
	size_t k, q;
	int a;

	if (size < 2)
		return;
	for (q = 0; q < size - 1; q++)
	{
		for (k = 0; k < size - q - 1; k++)
		{
			if (array[k] > array[k + 1])
			{
				a = array[k];
				array[k] = array[k + 1];
				array[k + 1] = a;
				print_array(array, size);
			}
		}
	}
}
