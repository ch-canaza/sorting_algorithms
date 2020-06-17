#include "sort.h"

/**
 * quick_sort -  function that sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: pointer to the array
 * @size: the size
 */
void quick_sort(int *array, size_t size)
{
	original_quick_sort(array, 0, size - 1, size);
}

/**
 * original_quick_sort - recursive sort function
 * @array: pointer to the array
 * @size: array size
 * @first_idx: the first_idx
 * @last_idx: the hish limit
 */
void original_quick_sort(int *array, int first_idx, int last_idx, size_t size)
{
	int location;

	if (first_idx < last_idx)
	{
		location = partition(array, first_idx, last_idx, size);
		original_quick_sort(array, first_idx, location - 1, size);
		original_quick_sort(array, location + 1, last_idx, size);
	}
}

/**
 * partition - function tha creates a partition and order the array
 * @array: the array
 * @size: the size
 * @first_idx: the first_idx limit
 * @last_idx: the hish limit
 * Return: return the pivot location
 */
size_t partition(int *array, int first_idx, int last_idx, size_t size)
{
	int location, i, j, temp;

	location = array[last_idx];

	i = first_idx - 1;
	for (j = first_idx; j < last_idx; j++)
	{
		if (array[j] <= location)
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
	i++;
	if (i != j)
	{
		temp = array[i];
		array[i] = array[last_idx];
		array[last_idx] = temp;
		print_array(array, size);
	}
	return (i);
}
