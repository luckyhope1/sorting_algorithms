#include "sort.h"

/**
 * selection_sort - Implementation of selection Sort Algrithme
 * @array: Array to sort type int *
 * @size: The Size of The Given Array
 *
 * Return: (Void) Sorted Array
 */
void selection_sort(int *array, size_t size)
{
	size_t q, index;
	int tmp, swap, flag = 0;

	if (array == NULL)
		return;
	for (q = 0; q < size; q++)
	{
		tmp = q;
		flag = 0;
		for (index = q + 1; index < size; index++)
		{
			if (array[tmp] > array[index])
			{
				tmp = index;
				flag += 1;
			}
		}
		swap = array[q];
		array[q] = array[tmp];
		array[tmp] = swap;
		if (flag != 0)
			print_array(array, size);
	}
}
