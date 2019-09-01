#include <include.h>
#include STACK_STATIC_H

STACK_ELEMENT_TYPE Stack[STACK_MAX_SIZE];

int Stack_Top = STACK_EMPTY;

static unsigned char IsStackFull(void)
{
	if (Stack_Top == (STACK_MAX_SIZE-1))
	{
		return 1;
	}

	return 0;
}

static unsigned char IsStackEmpty(void)
{
	if (Stack_Top == STACK_EMPTY)
	{
		return 1;
	}

	return 0;
}

int Stack_Push(STACK_ELEMENT_TYPE Element)
{
	if (IsStackFull())
	{
		return -1;
	}

	else if (IsStackEmpty())
	{
		Stack_Top = 0;
	}

	else
	{
		Stack_Top++;
	}

	Stack[Stack_Top] = Element;

	return 1;
}

STACK_ELEMENT_TYPE Stack_Pop(void)
{
	STACK_ELEMENT_TYPE Return_Element = 0;

	if (IsStackEmpty())
	{
		Return_Element = -1;
	}

	else if (Stack_Top == 0)
	{
		Return_Element = Stack[Stack_Top];

		Stack_Top = STACK_EMPTY;
	}

	else
	{
		Return_Element = Stack[Stack_Top];

		Stack_Top--;
	}

	return Return_Element;
}

STACK_ELEMENT_TYPE Stack_Peek(void)
{
	if (IsStackEmpty())
	{
		return -1;
	}

	else
	{
		return Stack[Stack_Top];
	}
}

int Stack_Traverse(void)
{
	unsigned char i;

	if (Stack_Top == STACK_EMPTY)
	{
		return -1;
	}
	else
	{
		for (i = 0; i <= Stack_Top; i++)
		{
			printf("Element [%d] : %d\n", i, Stack[i]);
		}
		return 1;
	}
}