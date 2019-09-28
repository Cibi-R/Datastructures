#include <include.h>
#include CIRCULAR_LIST_H

MyCircularList* GetCircularList(void)
{
	MyCircularList *NewList = (MyCircularList*)malloc(sizeof(MyCircularList));

	if (NewList != NULL)
	{
		NewList->Element = 0;
		NewList->Next = NULL;
	}

	return NewList;
}

unsigned char CircularList_PushElement(MyCircularList* List, CIRCULAR_LIST_ELEMENT_TYPE Element)
{
	unsigned char RetVal = 1;

	MyCircularList* NewNode = (MyCircularList*)malloc(sizeof(MyCircularList));

	MyCircularList* Temp = List;

	/* List is not created */
	if (Temp == NULL)
	{
		RetVal = 0;
	}

	else if (Temp->Next == NULL)
	{
		Temp->Next = NewNode;

		NewNode->Next = NewNode;
	}

	else
	{
		NewNode->Next = (Temp->Next)->Next;

		(Temp->Next)->Next = NewNode;

		Temp->Next = NewNode;
	}

	NewNode->Element = Element;

	return RetVal;
}

CIRCULAR_LIST_ELEMENT_TYPE CircularList_PopElement(MyCircularList* List)
{

}

unsigned char CircularList_InsertElement(MyCircularList* List, CIRCULAR_LIST_ELEMENT_TYPE Element)
{

}

CIRCULAR_LIST_ELEMENT_TYPE CircularList_RemoveElement(MyCircularList* List)
{

}

void CircularList_Traverse(MyCircularList* List)
{
	if (List == NULL)
	{
		printf_s("Circular list is not created!\n");
	}

	else if (List->Next == NULL)
	{
		printf_s("Circular list is empty!\n");
	}

	else 
	{
		MyCircularList* Temp = List->Next;
		do
		{
			printf_s("Element : %d\n", Temp->Element);

			Temp = Temp->Next;

			/*printf_s("Address 1 : %d\n", Temp);
			printf_s("Address 2 : %d\n", List->Next);*/
		}while(Temp != List->Next);

		printf_s("Traverse completed!\n");
	}
}