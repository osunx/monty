#include "monty.h"

/**
 * push - adds a new node with the given integer to the stack
 * @head: pointer to the head of the stack
 * @counter: line number
 * Return: no return
 */
void push(stack_t **head, unsigned int counter)
{
	int value, index = 0, nonDigitFlag = 0;

	/* Check if argument (integer) is provided */
	if (bus.arg)
	{
		/* Check if the number is negative */
		if (bus.arg[0] == '-')
			index++;

		/* Check if all characters are digits */
		for (; bus.arg[index] != '\0'; index++)
		{
			if (bus.arg[index] > '9' || bus.arg[index] < '0')
				nonDigitFlag = 1;
		}

		/* If non-digit characters are present, print an error and exit */
		if (nonDigitFlag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			freestack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* If no argument is provided, print an error and exit */
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}

	/* Convert the argument to an integer using atoi */
	value = atoi(bus.arg);

	/* Add the node to the stack based on lifo or fifo */
	if (bus.lifo == 0)
		addnode(head, value);
	else
		addqueue(head, value);
}
