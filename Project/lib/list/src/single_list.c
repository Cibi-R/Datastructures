#include <include.h>
#include SINGLE_LIST_H


MySingleList* GetSingleList(void)
{
	MySingleList *NewList = (MySingleList*)malloc(sizeof(MySingleList));

	if (NewList != NULL)
	{
		NewList->Next = NULL;

		/* "Element" member of headnode is used to store the Size of the list. */
		NewList->Element = -1;
	}

	return NewList;
}

unsigned char SingleList_PushElement(MySingleList* HeadNode, ELEMENT_TYPE_SINGLE_LIST Element)
{
	MySingleList* NewNode = (MySingleList*)malloc(sizeof(MySingleList));

	if ((HeadNode != NULL) && (NewNode != NULL))
	{
		if (HeadNode->Next == NULL)
		{
			HeadNode->Next = NewNode;
		}

		else
		{
			MySingleList* TempNode;

			TempNode = HeadNode;

			while (TempNode->Next != NULL)
			{
				TempNode = TempNode->Next;
			}

			TempNode->Next = NewNode;
		}

		NewNode->Element = Element;

		NewNode->Next = NULL;

		/* Element member of headnode is used as a Size of the list. */
		HeadNode->Element++;

		return 1;
	}

	else
	{
		/* Incase of failure of insertion delete the newly created node. */
		if (NewNode != NULL) { free(NewNode); }
	}
}

ELEMENT_TYPE_SINGLE_LIST SingleList_GetElement(MySingleList* HeadNode,unsigned char Position)
{
	ELEMENT_TYPE_SINGLE_LIST RetElement = 0;

	if ((HeadNode != NULL) || (Position < HeadNode->Element))
	{
		MySingleList* CurrentNode = HeadNode;

		int Current_Position = -1;

		while ((CurrentNode->Next != NULL) && (Current_Position < Position))
		{
			CurrentNode = CurrentNode->Next;

			Current_Position++;
		}

		RetElement = CurrentNode->Element;
	}

	return RetElement;
}

unsigned char SingleList_InsertElement(MySingleList* HeadNode, ELEMENT_TYPE_SINGLE_LIST Element, unsigned int Position)
{
	unsigned char RetVal = 0;

	if ((HeadNode != NULL) || (Position <= HeadNode->Element))
	{
		MySingleList *NewNode = (MySingleList*)malloc(sizeof(MySingleList));

		if (NewNode != NULL)
		{
			MySingleList* Temp = HeadNode;

			int Current_Position = -1;

			if (NewNode != NULL)
			{
				while ((Temp->Next != NULL) && (Current_Position < (Position - 1)))
				{
					Temp = Temp->Next;

					Current_Position++;
				}

				NewNode->Next = Temp->Next;

				Temp->Next = NewNode;

				HeadNode->Element++;

				RetVal = 1;
			}
		}
	}

	return RetVal;
}

ELEMENT_TYPE_SINGLE_LIST SingleList_RemoveElement(MySingleList *HeadNode, unsigned int Position)
{
	ELEMENT_TYPE_SINGLE_LIST RetElement = 0;

	if ((HeadNode != NULL) || (Position < HeadNode->Element))
	{
		MySingleList *CurrentNode = HeadNode;

		MySingleList *PreviousNode;

		int Current_Position = -1;

		while ((CurrentNode->Next != NULL) && (Current_Position < Position))
		{
			PreviousNode = CurrentNode;

			CurrentNode = CurrentNode->Next;

			Current_Position++;
		}

		//PreviousNode->Next = CurrentNode->Next;

		RetElement = CurrentNode->Element;

		free(CurrentNode);

		HeadNode->Element--;
	}

	return RetElement;
}

ELEMENT_TYPE_SINGLE_LIST SingleList_PopElement(MySingleList* HeadNode, unsigned int Position)
{
	ELEMENT_TYPE_SINGLE_LIST RetElement = 0;

	if (HeadNode != NULL)
	{
		MySingleList* CurrentNode = HeadNode;

		MySingleList* NextNode = CurrentNode->Next;

		while (NextNode->Next != NULL)
		{
			CurrentNode = CurrentNode->Next;

			NextNode = CurrentNode->Next;
		}

		CurrentNode->Next = NULL;

		RetElement = NextNode->Element;

		free(NextNode);

		HeadNode->Element--;
	}

	return RetElement;
}

