#include "sort.h"
void swap_array(int *array, int first_index, int second_index);

/**
 * bubble_sort - sorts an array using the bubble sort algorithm
 *
 * @array: The array to be sorted
 * @size: The size of the arrayt
 *
 * Return: void(Returns no value)
 */
void bubble_sort(int *array, size_t size)
{
	int has_swapped;
	size_t i;
	int j;
	size_t n;

	/* Variable to check if a swap has occured during the iteration */
	has_swapped = 1;
	n = size;

	while (has_swapped == 1)
	{
		has_swapped = 0;

		for (i = 0; i < n; i++)
		{
			j = *(array + i + 1);

			if (j < *(array + i))
			{
				swap_array(array, i, i + 1);
				print_array(array, size);
				has_swapped = 1;
			}
		}

		n--;
	}
}

/**
 * swap_array - swaps two elements of an array and prints the array
 *
 * @array: The array where the swap will take place
 * @first_index: The index to the first element to be swapped
 * @second_index: The index to the second element to be swapped
 *
 * Return: void(This function returns no value)
 */
void swap_array(int *array, int first_index, int second_index)
{
	int temp;

	temp = *(array + first_index);
	*(array + first_index) = *(array + second_index);
	*(array + second_index) = temp;
}
