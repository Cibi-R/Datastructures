#include <include.h>
#include STACK_DYNAMIC_H

/*
 * In this stack Head stack's element is used to store the size of that particular stack.
 */

MyStack* Get_MyStack(void)
{
	MyStack* NewStack = (MyStack*)malloc(sizeof(MyStack));

	if (NULL != NewStack)
	{
		/* Here Head's Element member is used as a length of the stack. */
		NewStack->Element = 0;

		NewStack->Next = NULL;
	}

	return NewStack;
}

void Push_MyStack(MyStack* StackHead, STACK_ELEMENT_TYPE_DYNAMIC Item)
{
	MyStack* NewNode = (MyStack*)malloc(sizeof(MyStack));

	if (NULL != NewNode)
	{
		NewNode->Element = Item;

		if (StackHead->Next == NULL)
		{
			NewNode->Next = NULL;
		}
		else
		{
			NewNode->Next = StackHead->Next;
		}
	}

	StackHead->Next = NewNode;

	/* Stack Head Element : For Stack Length */
	StackHead->Element++;
}

STACK_ELEMENT_TYPE_DYNAMIC Pop_MyStack(MyStack* StackHead)
{
	STACK_ELEMENT_TYPE_DYNAMIC ReturnElement = 0;

	if (StackHead->Next != NULL)
	{
		MyStack* Delete = StackHead->Next;
		ReturnElement = Delete->Element;
		StackHead->Next = Delete->Next;
		free(Delete);
		
		/* Stack Head Element : For Stack Length */
		StackHead->Element--;
	}

	return ReturnElement;
}

STACK_ELEMENT_TYPE_DYNAMIC Peek_MyStack(MyStack* StackHead)
{
	STACK_ELEMENT_TYPE_DYNAMIC ReturnElement = 0;

	if (StackHead->Next != NULL)
	{
		ReturnElement = (StackHead->Next)->Element;
	}

	return ReturnElement;
}

void Traverse_MyStack(MyStack* StackHead)
{
	if (StackHead->Next != NULL)
	{
		MyStack* Temp = StackHead->Next;

		while (Temp)
		{
			printf_s("%c",Temp->Element);
			Temp = Temp->Next;
		}
	}
}

STACK_ELEMENT_TYPE_DYNAMIC GetSize_MyStack(MyStack* StackHead)
{
	return StackHead->Element;
}

void Delete_MyStack(MyStack* StackHead)
{
	if (StackHead->Next != NULL)
	{
		MyStack* Current = StackHead->Next;
		MyStack* Previous = NULL;

		while (Current->Next)
		{
			Previous = Current;
			Current = Current->Next;
			free(Previous);
		}

		free(Current);
	}
}

      