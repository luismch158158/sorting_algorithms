#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list : double linked list
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node = NULL, *holder = NULL, *tmp = NULL;

	if (!list || !(*list) || (*list)->next == NULL)
		return;

	for (node = *list; node;)
	{
		if (node->next && (node->n >  node->next->n))
		{
			holder = node->next;
			for (tmp = holder; tmp->prev; tmp = tmp->prev)
				if ((tmp->prev->n) < (tmp->n))
					break;

			if (holder->next && holder->prev)
			{
				holder->prev->next = holder->next;
				holder->next->prev = holder->prev;
			}
			else
			{
				holder->prev->next = NULL;
			}
			holder->next = tmp;

			if (tmp->prev)
			{
				tmp->prev->next = holder, holder->prev = tmp->prev;
				tmp->prev = holder;
			}
			else
			{
				tmp->prev = holder, holder->prev = NULL;
				*list = holder;
			}
			print_list(*list), node = *list;
			continue;
		}
		node = node->next;
	}
}
