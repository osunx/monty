#include "monty.h"

/**
 * mul - multiplies the top two elements of the stack.
 * @head: pointer to the head of the stack
 * @counter: line_number
 * Return: no return
 */
void mul(stack_t **head, unsigned int counter)
{
	stack_t *currentNode;
	int product, stackLength;

	currentNode = *head;

	/* Calculate the length of the stack */
	for (stackLength = 0; currentNode != NULL; stackLength++)
		currentNode = currentNode->next;

	/* Check if the stack has less than 2 elements */
	if (stackLength < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}

	/* Calculate the product of the top two elements */
	currentNode = *head;
	product = currentNode->next->n * currentNode->n;
	currentNode->next->n = product;
	*head = currentNode->next;
	free(currentNode);
}
