#include "sort.h"

/**
 * swap_it - swaps two nodes
 * @list: head
 * @node: node
 * Return: Void
 */

void swap_it(listint_t **list, listint_t *node)
{
	if (node->next)
		node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
 * cocktail_sort_list - Sorts array
 * @list: Head
 * Return: Void
 */


void cocktail_sort_list(listint_t **list)
{
	int swap = 1;
	listint_t *temp = *list;

	if (list == NULL || *list == NULL)
		return;

	while (swap)
	{
		swap = 0;
		while (temp->next != NULL)
		{
			if (temp->n > temp->next->n)
			{
				swap_it(list, temp);
				print_list(*list);
				swap = 1;
			}
			else
				temp = temp->next;

		}
		if (swap == 0)
			break;
		swap = 0;
		while (temp->prev != NULL)
		{
			if (temp->n < temp->prev->n)
			{
				swap_it(list, temp->prev);
				print_list(*list);
				swap = 1;
			}
			else
				temp = temp->prev;
		}
	}
}
