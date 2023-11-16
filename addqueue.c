#include "monty.h"

/**
 * queue - sets the format of the data to a queue (FIFO)
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifo = 1;  /* Set lifo flag to 1 to indicate queue mode */
}

/**
 * addqueue - add node to the tail stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
 */
void addqueue(stack_t **head, int n)
{
	stack_t *newNode, *currentNode, *currentHead;

	currentHead = *head;  /* Save the current head of the stack */
	currentNode = currentHead;  /* Initialize current node to the head */

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		printf("Error\n");
		exit(0);
	}

	newNode->n = n;
	newNode->next = NULL;

	if (currentNode)
	{
		while (currentNode->next)
			currentNode = currentNode->next;
	}

	if (!currentNode)
	{
		*head = newNode;
		newNode->prev = NULL;
	}
	else
	{
		currentNode->next = newNode;
		newNode->prev = currentNode;
	}
}
