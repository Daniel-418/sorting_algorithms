#ifndef GUARD_H
#define GUARD_H
#include <stdlib.h>

/** Struct for the doubly linked list **/
/**
 * struct listint_s - Doubly linked list
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *next;
	struct listint_s *prev;
} listint_t;

/** Prototypes for the functions **/
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
#endif
