#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                        order using an insertion sort algorithm.
 * @list: Pointer to the doubly linked list of integers to be sorted.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *previous;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		previous = current->prev;
		while (previous && current->n < previous->n)
		{
			previous->next = current->next;
			if (current->next)
				current->next->prev = previous;
			current->next = previous;
			current->prev = previous->prev;
			if (previous->prev)
				previous->prev->next = current;
			else
				*list = current;
			previous->prev = current;
			print_list(*list);
			previous = current->prev;
		}
		current = current->next;
	}
}
