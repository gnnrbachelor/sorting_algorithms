#include "sort.h"

/**
 * swap_node - Swaps for sort
 * @var1: Variable 1
 * @var2: Variable 2
 * Return: Void
 */

void swap_node(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;

	node2->prev = (*node1)->prev;
	node2->next = *node1;

	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - Sorts doubly linked list
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
