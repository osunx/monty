#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @head: pointer to the head of the stack
 * @counter: line_number
 * Return: no return
 */
void pop(stack_t **head, unsigned int counter)
{
        stack_t *topNode;

        /* Check if the stack is empty */
        if (*head == NULL)
        {
                fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
                fclose(mover.file);
                free(mover.content);
                freestack(*head);
                exit(EXIT_FAILURE);
        }

        /* Save the top node */
        topNode = *head;

        /* Update the head of the stack to the next node */
        *head = topNode->next;

        /* Free the memory of the top node */
        free(topNode);

        /* Debugging output */
        printf("Popped value: %d\n", topNode->n);
}
