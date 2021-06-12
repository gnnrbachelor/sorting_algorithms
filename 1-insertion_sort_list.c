#include "sort.h"

/**
 * insertion_sort - Sorts doubly linked list
 * @list: head of list
 * Return: Void
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp1 = NULL;
	listint_t *temp2 = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	temp1 = (*list)->next;
	while (temp1 != NULL)
	{
		temp2 = temp1->prev;
		while (temp2 != NULL && temp1->n < temp2->n)
		{
			swap_node(list, &temp2, temp1);
			print_list((const listint_t *) *list);
		}
		temp1 = temp1->next;
	}
}
