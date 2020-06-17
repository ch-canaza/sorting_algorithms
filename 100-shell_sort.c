#include "sort.h"
/**
 * shell_sort - function that sorts an array of integers in
 * ascending order using the Shell
 * sort algorithm, using the Knuth sequence
 * @array: pointer to the array
 * @size: size of the array
 * Return: nothing
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
		int temp;

	if (array == NULL || size < 2)
		return;
	while (gap < size)
		gap = (gap * 3) + 1;
	gap = (gap - 1) / 3;
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];

			}
			array[j] = temp;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
