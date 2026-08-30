#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - deletes a node at a given index
 * @head: pointer to the first node
 * @index: index of the node to delete
 *
 * Return: 1 if successful, -1 if it fails
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;

	for (i = 0; current != NULL && i < index; i++)
		current = current->next;

	if (current == NULL)
		return (-1);

	if (index == 0)
	{
		*head = current->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	current->prev->next = current->next;

	if (current->next != NULL)
		current->next->prev = current->prev;

	/* Required fix for the original broken pointer assignment */
	if (index > 0 && current == *head)
		(*head)->prev->next = (*head)->next;

	free(current);

	return (1);
}
