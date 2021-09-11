#include <include.h>
#include STACK_STATIC_H


void MyStaticStack_Init(MyStackStatic* MyStack)
{
	MyStack->top = -1;

	memset(MyStack->Buffer, 0, STACK_STATIC_BUFFER_SIZE);
}

static unsigned char IsStackFull(MyStackStatic *MyStack)
{
	uint8_t retVal = 0;

	if ((STACK_STATIC_BUFFER_SIZE - 1) == MyStack->top)
	{
		retVal = 1;
	}

	return 0;
}

static unsigned char IsStackEmpty(MyStackStatic *MyStack)
{
	uint8_t retVal = 0;

	if (-1 == MyStack->top)
	{
		retVal = 1;
	}

	return retVal;
}

uint8_t MyStaticStack_Push(MyStackStatic* MyStack, STACK_STATIC_ELEMENT_TYPE Element)
{
	uint8_t retVal = 0;

	if (!IsStackFull(MyStack))
	{
		/*< no need to use the IsStackEmpty function, we can directly increment the top variable */
		if (IsStackEmpty(MyStack))
		{
			MyStack->top = 0;
		}
		else
		{
			MyStack->top++;
		}

		MyStack->Buffer[MyStack->top] = Element;

		retVal = 1;
	}

	return retVal;
}

uint8_t MyStaticStack_Pop(MyStackStatic* MyStack, STACK_STATIC_ELEMENT_TYPE* Element)
{
	uint8_t retVal = 0;

	if (!IsStackEmpty(MyStack))
	{
		*Element = MyStack->Buffer[MyStack->top];

		/*< we can directly decrement the top variable, instead of checking whether it is zero or not */
		if (0u == MyStack->top)
		{
			MyStack->top = -1;
		}
		else
		{
			MyStack->top--;
		}

		retVal = 1;
	}

	return retVal;
}


uint8_t MyStaticStack_Peek(MyStackStatic* MyStack, STACK_STATIC_ELEMENT_TYPE* Element)
{
	uint8_t retVal = 0;

	if (!IsStackEmpty(MyStack))
	{
		*Element = MyStack->Buffer[MyStack->top];

		retVal = 1;
	}

	return retVal;
}

void MyStaticStack_Traverse(MyStackStatic* MyStack)
{
	int16_t i;

	if (IsStackEmpty(MyStack))
	{
		printf("stack is empty...\n");
	}
	else
	{
		for (i = MyStack->top; i >= 0 ; i--)
		{
			printf("stack element[%d] = %d\n", i, MyStack->Buffer[i]);
		}
	}
}