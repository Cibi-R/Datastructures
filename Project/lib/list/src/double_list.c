#include <include.h>
#include DOUBLE_LIST_H

MyDoubleList* GetMyDoubleList(void)
{
	MyDoubleList* NewList = (MyDoubleList*)malloc(sizeof(MyDoubleList));

	if (NewList != NULL)
	{
		NewList->Previous = NULL;
		NewList->Element  = 0;
		NewList->Next     = NULL;
	}

	return NewList;
}

unsigned char DoubleList_PushElement(MyDoubleList* List, DOUBLE_LIST_ELEMENT_TYPE Element)
{
	unsigned char RetVal = 1;

	MyDoubleList* NewNode = (MyDoubleList*)malloc(sizeof(MyDoubleList));

	if ((List == NULL) || (NewNode == NULL))
	{
		RetVal = 0;

		if (NewNode != NULL)
		{
			/* If Newnode is not NULL, Clear the node because we are not pushing the element. */
			free(NewNode);
		}
	}

	else if (List->Next == NULL)
	{
		List->Next = NewNode;

		NewNode->Previous = NULL;
		NewNode->Next = NULL;
	}

	else
	{
		MyDoubleList* Temp = List->Next;

		while (Temp->Next != NULL)
		{
			Temp = Temp->Next;
		}

		Temp->Next = NewNode;

		NewNode->Previous = Temp;
		NewNode->Next = NULL;
	}

	NewNode->Element = Element;

	return RetVal;
}

DOUBLE_LIST_ELEMENT_TYPE DoubleList_PopElement(MyDoubleList* List)
{

}

unsigned char DoubleList_InsertElement(MyDoubleList* List, DOUBLE_LIST_ELEMENT_TYPE Element,unsigned char Position)
{

}

DOUBLE_LIST_ELEMENT_TYPE DoubleList_RemoveElement(MyDoubleList* List,unsigned char Position)
{

}

void DoubleList_TraverseElement(MyDoubleList* List)
{
	if (List != NULL)
	{
		if (List->Next == NULL)
		{
			printf_s("Double is empty!\n");
		}

		else
		{
			List = List->Next;

			do 
			{
				printf_s("Element : %d\n", List->Element);
				List = List->Next;
			} while (List != NULL);
		}
	}

	else
	{
		printf_s("Double list is not created!\n");
	}


}





