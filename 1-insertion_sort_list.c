#include "sort.h"
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2);

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 *
 * @n1: first node to be swapped
 * @n2: second node to be swapped
 * @h: head of the list
 *
 * Return: void
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort
 * @list: The list to be sorted
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *marker, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = temp)
	{
		temp = current->next;
		marker = current->prev;
		while (marker != NULL && current->n < marker->n)
		{
			swap_nodes(list, &marker, current);
			print_list((const listint_t *)*list);
		}
	}
}

