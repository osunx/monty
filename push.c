#include "monty.h"

/**
 * f_push - add node to the stack
 * @stackHead: pointer to the head of the stack
 * @lineNumber: line number
 * Return: no return
 */
void push(stack_t **stackHead, unsigned int lineNumber)
{
        int integerValue, index = 0, errorFlag = 0;

        if (bus.arg)
        {
                if (bus.arg[0] == '-')
                        index++;
                for (; bus.arg[index] != '\0'; index++)
                {
                        if (bus.arg[index] > 57 || bus.arg[index] < 48)
                                errorFlag = 1;
                }
                if (errorFlag == 1)
                {
                        fprintf(stderr, "L%d: usage: push integer\n", lineNumber);
                        fclose(bus.file);
                        free(bus.content);
                        freestack(*stackHead);
                        exit(EXIT_FAILURE);
                }
        }
        else
        {
                fprintf(stderr, "L%d: usage: push integer\n", lineNumber);
                fclose(bus.file);
                free(bus.content);
                freestack(*stackHead);
                exit(EXIT_FAILURE);
        }

        integerValue = atoi(bus.arg);
        if (bus.lifi == 0)
                addnode(stackHead, integerValue);
        else
                addqueue(stackHead, integerValue);
}
