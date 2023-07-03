#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order using the
 * Counting sort algorithm.
 *
 * Assume that array will contain only numbers >= 0.
 * You are allowed to use malloc and free.
 * Print your counting array once it is set up.
 * This array is of size k + 1 where k is the largest number in array.
 *
 * @array: pointer to array of integers to sort.
 * @size: size of array.
 *
 * Return: No return.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output, max = 0, k;

	if (!array || size < 2)
		return;

	/* Find the maximum value in the array and printing the sorted array.*/

	for (k = 0; k < (int)size; k++)
		if (array[k] > max)
			max = array[k];
	count = malloc(sizeof(int) * (max + 1));
	output = malloc(sizeof(int) * size);
	if (!count || !output)
		return;
	for (k = 0; k <= max; k++)
		count[k] = 0;
	for (k = 0; k < (int)size; k++)
		count[array[k]] += 1;
	for (k = 1; k <= max; k++)
		count[k] += count[k - 1];
	print_array(count, max + 1);
	for (k = 0; k < (int)size; k++)
	{
		output[count[array[k]] - 1] = array[k];
		count[array[k]] -= 1;
	}
	for (k = 0; k < (int)size; k++)
		array[k] = output[k];
	free(count);
	free(output);
}
