#include "sort.h"

/**
* shell_sort -Sort an array using shell_sort algorithm
* @array: array
* @size: size of the array
* Return: NULL
**/
void shell_sort(int *array, size_t size)
{
unsigned int gap = 1, i, j;
int temp;

if (array == NULL)
return;
if (size &lt; 2)
return;
while (gap &lt; size / 3)
gap = gap * 3 + 1;

while (gap &gt; 0)
{
for (i = gap; i &lt; size; i++)
{
temp = array[i];
j = i;
while (j &gt;= gap &amp;&amp; array[j - gap] &gt; temp)
{

array[j] = array[j - gap];
j -= gap;
}
array[j] = temp;
}
print_array(array, size);
gap /= 3;
}
}
