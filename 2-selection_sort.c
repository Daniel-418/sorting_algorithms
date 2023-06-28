#include "sort.h"

/**
 * swap_ints -This swap two integers in an array.
 * @a: This shows the first integer to swap.
 * @b: This shows the second integer to swap.
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - It sort array of integers in ascending order
 *                  using selection sort algorithm.
 * @array: Shows an array of integers.
 * @size: Shows the size of the array.
 *
 * Description: It prints array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t j, k;

	if (array == NULL || size < 2)
		return;

	for (j = 0; j < size - 1; j++)
	{
		min = array + j;
		for (k = j + 1; k < size; k++)
			min = (array[k] < *min) ? (array + k) : min;

		if ((array + j) != min)
		{
			swap_ints(array + j, min);
			print_array(array, size);
		}
	}
}
