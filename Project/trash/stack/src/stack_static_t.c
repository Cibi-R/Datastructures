#include <include.h>
#include STACK_STATIC_H

void UnitTest1_MyStaticStack(void)
{
	MyStackStatic MyStack;

	MyStaticStack_Init(&MyStack);

	unsigned int option;

	printf(" ****************************************************************************************************\n \
		                        My Static stack Unit Test 1                                           \n \
****************************************************************************************************\n");

	while (1)
	{
		printf("### Enter the option ###\n");
		printf_s("1. Push\n2. Pop\n3. Peek\n4. Traverse\n");
		scanf_s("%d", &option);

		switch (option)
		{
			case 1:
				printf("Enter the element : ");
				scanf_s("%d",&option);
				(MyStaticStack_Push(&MyStack, option)) ? printf_s("Element Pushed Successfully!\n") : printf_s("Stack Full!\n");
			break;

			case 2:
				(MyStaticStack_Pop(&MyStack, &option)) ? printf_s("Popped element : %d\n", option) : printf_s("Stack Empty!\n");
				break;

			case 3:
				(MyStaticStack_Peek(&MyStack, &option)) ? printf_s("Peek element : %d\n", option) : printf_s("Stack Empty!\n");
				break;

			case 4:
				MyStaticStack_Traverse(&MyStack);
				break;
		}
	}
}

#if 0
/*
 * Baseball Game.
 */

int calPoints(char**ops, int opsSize)
{
	unsigned int Point1 = 0, Point2 = 0;

	char* str = *ops;

	while (*str)
	{
		switch (*str)
		{
			case '+':
			{
				Point2 = Stack_Pop();
				Point1 = Stack_Pop();
				Stack_Push(Point1);
				Stack_Push(Point2);
				Stack_Push(Point1+Point2);
				break;
			}

			case 'D':
			{
				Point1 = Stack_Peek();
				Stack_Push(Point1*2);
				break;
			}

			case 'C':
			{
				Point1 = Stack_Pop();
				break;
			}

			default:
			{
				Stack_Push(*str-0x30);
				break;
			}
		}
		str++;
	}
}

#endif

