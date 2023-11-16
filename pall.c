#include "monty.h"

/**
 * pall - prints the stack
 * @head: pointer to the head of the stack
 * @counter: unused parameter
 * Return: no return
 */
void pallmonty(stack_t **head, unsigned int counter)
{
	stack_t *currentNode;
	(void)counter;

	currentNode = *head;

	/* Print each element in the stack */
	while (currentNode)
	{
		printf("%d\n", currentNode->n);
		currentNode = currentNode->next;
	}
}
