#include "sort.h"

/**
 * quick_sort - the original_quick_sort algorithm
 * @array: array to sort
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	original_quick_sort(array, 0, size - 1, size);
}

/**
 * original_quick_sort - recursively implements original_quick_sort
 * @array: array to sort
 * @first_idx: first_idx index
 * @last_idx: last_idx index
 * @size: size of array
 */

void original_quick_sort(int *array, size_t first_idx, size_t last_idx,
			 size_t size)
{
	size_t i;

	if (first_idx < last_idx)
	{
		i = partition(array, first_idx, last_idx, size);
		original_quick_sort(array, first_idx, i - 1, size);
		original_quick_sort(array, i + 1, last_idx, size);
	}
}


/**
 * partition - partitions array into two subarrays
 * @array: pointer to the array
 * @first_idx: first_idx index
 * @last_idx: last_idx index
 * @size: size of array
 *
 * Return: partition index
 */

size_t partition(int *array, size_t first_idx, size_t last_idx, size_t size)
{
	size_t i, j;
	int pivot, temp;

	i = first_idx - 1;
	pivot = array[last_idx];
	for (j = first_idx; j <= last_idx - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[last_idx] < array[i + 1])
	{
		temp = array[last_idx];
		array[last_idx] = array[i + 1];
		array[i + 1] = temp;
		print_array(array, size);
	}
	return (i + 1);
}
