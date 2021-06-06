#include <include.h>
#include STACK_DYNAMIC_H


unsigned char GetMyDynamicStack(MyDynamicStack** MyStack)
{
	unsigned char retval = 0;

	*MyStack = (MyDynamicStack*)malloc(sizeof(MyDynamicStack));

	if (*MyStack != NULL)
	{
		(*MyStack)->Previous = NULL;
		(*MyStack)->Element = 0;

		retval = 1;
	}

	return retval;
}

unsigned char PushMyDynamicStack(MyDynamicStack* StackHead, DYNAMIC_STACK_ELEMENT_TYPE ElementValue)
{
	unsigned char retval = 0;
	MyDynamicStack* NewNode = NULL;

	if (StackHead != NULL)
	{
		NewNode = (MyDynamicStack*)malloc(sizeof(MyDynamicStack));

		if (NewNode != NULL)
		{
			/*< If StackHead->Previous is null, then the stack is empty */
			if (StackHead->Previous == NULL)
			{
				StackHead->Previous = NewNode;

				/*< first node in the stack */
				NewNode->Previous = NULL;
			}

			else
			{
				/*< NewNode is the top of the stack, so link previous top node to the NewNode */
				NewNode->Previous = StackHead->Previous;

				/*< Assign StackHead->Previous to NewNode as this is the top of the stack */
				StackHead->Previous = NewNode;
			}

			/*< Load the value */
			NewNode->Element = ElementValue;

			retval = 1;
		}
	}

	return retval;
}

unsigned char PopMyDynamicStack(MyDynamicStack* StackHead, DYNAMIC_STACK_ELEMENT_TYPE* ElementValue)
{
	unsigned char retval = 0;
	MyDynamicStack* TempNode = NULL;

	if (StackHead != NULL)
	{
		/*< stack is empty */
		if (StackHead->Previous != NULL)
		{
			TempNode = StackHead->Previous;

			/*< Last node of the stack */
			if (TempNode->Previous == NULL)
			{
				StackHead->Previous = NULL;
			}
			else
			{
				/*< Make the StackHead point to previous node of the stack */
				StackHead->Previous = TempNode->Previous;
			}

			*ElementValue = TempNode->Element;

			free(TempNode);

			retval = 1;
		}
	}

	return retval;
}


unsigned char PeekMyDynamicStack(MyDynamicStack* StackHead, DYNAMIC_STACK_ELEMENT_TYPE* ElementValue)
{
	unsigned char retval = 0;

	if (StackHead != NULL)
	{
		/*< stack is empty */
		if (StackHead->Previous != NULL)
		{
			*ElementValue = (StackHead->Previous)->Element;

			retval = 1;
		}
	}

	return retval;
}

void TraverseMyDynamicStack(MyDynamicStack* StackHead)
{
	MyDynamicStack* TempNode = NULL;

	if (StackHead != NULL)
	{
		TempNode = StackHead->Previous;

		if (TempNode != NULL)
		{
			do
			{
				printf("stack element : %d\n", TempNode->Element);

				TempNode = TempNode->Previous;
			} while (TempNode != NULL);
		}
		else
		{
			printf("stack is empty\n");
		}
	}
	else
	{
		printf("stack is not created\n");
	}
}

      