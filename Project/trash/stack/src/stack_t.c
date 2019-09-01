#include <include.h>
#include STACK_STATIC_H

void Execute_Stack(void)
{
	unsigned int Option;

	while (1)
	{
		printf_s("1. Push\n2. Pop\n3. Peek\n4. Traverse\n");
		scanf_s("%d", &Option);

		switch (Option)
		{
		case 1:
			printf("Enter the Element:");
			scanf_s("%d",&Option);
			(Stack_Push(Option)) ? printf_s("Element Pushed Successfully!\n") : printf_s("Stack Full!\n");
			break;
		case 2:
			printf("Popped Element : %d\n", Stack_Pop());
			break;
		case 3:
			printf("Peek Element : %d\n", Stack_Peek());
			break;
		case 4:
			(Stack_Traverse(Option)) ? printf_s("\n") : printf_s("Stack Empty!\n");
			break;
		}
	}
}

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

