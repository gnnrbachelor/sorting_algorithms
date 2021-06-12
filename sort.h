#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void swap(int *var1, int *var2);
void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void swap_node(listint_t **head, listint_t **node1, listint_t *node2);
void insertion_sort_list(listint_t **list);
void swap_sel(int *var1, int *var2);

#endif
