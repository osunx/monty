#include "monty.h"

/**
 * pint - prints the top element of the stack
 * @head: pointer to the head of the stack
 * @counter: line number
 * Return: no return
 */
void pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
