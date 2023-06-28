#include "sort.h"


/**
 * swap_ints - It swap two integers in an array.
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
 * shell_sort - It sort an array of integers in ascending
 *              order using shell sort algorithm.
 * @array: Shows an array of integers.
 * @size: Show the size of the array.
 *
 * Description: It uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
    size_t gap, i, j;


    if (array == NULL || size < 2)
        return;


    for (gap = 1; gap < (size / 3);)
        gap = gap * 3 + 1;


    for (; gap >= 1; gap /= 3)
    {
        for (i = gap; i < size; i++)
        {
            j = i;
            while (j >= gap && array[j - gap] > array[j])
            {
                swap_ints(array + j, array + (j - gap));
                j -= gap;
            }
        }
        print_array(array, size);
    }
}
