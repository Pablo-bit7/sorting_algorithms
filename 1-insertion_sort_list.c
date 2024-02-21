#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                      in ascending order using Insertion sort algorithm
 *
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		temp = current;
		prev = current->prev;

		while (prev && prev->n > temp->n)
		{
			if (temp->next)
				temp->next->prev = prev;
			prev->next = temp->next;
			temp->next = prev;
			temp->prev = prev->prev;
			prev->prev = temp;

			if (temp->prev)
				temp->prev->next = temp;
			else
				*list = temp;

			print_list(*list);
			prev = temp->prev;
		}
		current = current->next;
	}
}
