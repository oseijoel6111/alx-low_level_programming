#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at index index of a dlistint_t linked list.
 * @head: A pointer to a pointer to the head of the doubly linked list.
 * @index: The index of the node to be deleted (index starts at 0).
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current, *temp;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return -1;

	current = *head;

	if (index == 0)
	{
		*head = current->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return 1;
	}

	for (i = 0; i < index && current != NULL; i++)
		current = current->next;

	if (current == NULL)
		return -1;

	temp = current->prev;
	if (temp != NULL)
		temp->next = current->next;

	temp = current->next;
	if (temp != NULL)
		temp->prev = current->prev;

	free(current);

	return 1;
}
