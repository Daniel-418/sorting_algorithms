#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - This swap two integers in an array.
 * @a: Shows the first integer to swap.
 * @b: Shows the second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - This order subset of an array of integers according to
 *                    the lomuto partition scheme.
 * @array: Shows the array of integers.
 * @size: Shows the size of the array.
 * @left: Shows the starting index of the subset to order.
 * @right: Shows the ending index of the subset to order.
 *
 * Return: Shows the final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *driver, up, down;

	driver = array + right;
	for (up = down = left; down < right; down++)
	{
		if (array[down] < *driver)
		{
			if (up < down)
			{
				swap_ints(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *driver)
	{
		swap_ints(array + up, driver);
		print_array(array, size);
	}

	return (up);
}

/**
 * lomuto_sort - This implement quicksort algorithm through recursion.
 * @array: Shows an array of integers to sort.
 * @size: Shows the size of the array.
 * @left: Shows the starting index of array partition to order.
 * @right: Shows the ending index of array partition to order.
 *
 * Description: It uses  Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int belong;

	if (right - left > 0)
	{
		belong = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, belong - 1);
		lomuto_sort(array, size, belong + 1, right);
	}
}

/**
 * quick_sort - It sort an array of integers in ascending
 *              order using  quicksort algorithm.
 * @array:Shoes an array of integers.
 * @size: Shows the size of the array.
 *
 * Description: It uses Lomuto partition scheme. Prints
 *              array after each swap of elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
