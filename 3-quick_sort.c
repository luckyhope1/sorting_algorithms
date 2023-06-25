#include "sort.h"

/**
*swap - the positions of two elements into an array
*
*@a: first element to be swapped
*@b: second element to be swapped
*/
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 *partition - partition sorting scheme implementation
 *@array: array
 *@high: high array element
 *@low: low array element
 *
 *Return: return the position of the last element sorted
 */
int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

/**
 *quick_sort_recursive - qucksort algorithm implementation
 *@array: array
 *@high: high array element
 *@low: low array element
 *
 */
void quick_sort_recursive(int *array, int low, int high)
{
	if (low < high)
	{
		int pi = partition(array, low, high);

		quick_sort_recursive(array, low, pi - 1);
		quick_sort_recursive(array, pi + 1, high);
	}
}

/**
 *quick_sort - prepare the terrain to quicksort algorithm
 *@array: array
 *@size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1);
}

