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

		/* Element member of headnode is used to store the Size of list. */
		HeadNode->Element++;

		return 1;
	}

	else
	{
		/* Incase of failure of insertion delete the newly created node. */
		if (NewNode != NULL) { free(NewNode); }
	}
}

ELEMENT_TYPE_SINGLE_LIST SingleList_GetElement(MySingleList* MyList,unsigned char Position)
{
	ELEMENT_TYPE_SINGLE_LIST RetElement = 0;

	if ((MyList != NULL) && (MyList->Next != NULL))
	{
		MySingleList* CurrentNode = MyList->Next;

		if (CurrentNode != NULL)
		{
			/* We are already in the 0th position so, value 0 */
			int Current_Position = 0;

			while ((CurrentNode->Next != NULL) && (Current_Position < Position))
			{
				CurrentNode = CurrentNode->Next;

				Current_Position++;
			}

			if (Current_Position == Position)
			{
				RetElement = CurrentNode->Element;
			}
		}

		else
		{
			RetElement = 0;
		}
	}

	return RetElement;
}

unsigned char SingleList_InsertElement(MySingleList* MyList, ELEMENT_TYPE_SINGLE_LIST Element, int Position)
{
	unsigned char RetVal = 0;

	if (MyList != NULL)
	{
		MySingleList *NewNode = (MySingleList*)malloc(sizeof(MySingleList));

		if (NewNode != NULL)
		{
			MySingleList* CurrentNode = MyList;

			/* We are in head pointer so, value -1 */
			int CurrentPosition = -1;

			while ((MyList->Next != NULL) && (CurrentPosition < (Position - 1)))
			{
				MyList = MyList->Next;
				CurrentPosition++;
			}

			if (CurrentPosition == (Position - 1))
			{
				NewNode->Next = MyList->Next;
				MyList->Next = NewNode;
				NewNode->Element = Element;
				RetVal = 1;
			}
			else { free(NewNode); /* Free the element incase of failure. */ }
		}
	}

	return RetVal;
}

ELEMENT_TYPE_SINGLE_LIST SingleList_RemoveElement(MySingleList * MyList,int Position)
{
	ELEMENT_TYPE_SINGLE_LIST RetElement = 0;

	if (MyList != NULL)
	{
		if (MyList->Next != NULL)
		{
			int CurrentPosition = -1;

			while ((MyList->Next != NULL) && (CurrentPosition < (Position - 1)))
			{
				MyList = MyList->Next;
				CurrentPosition++;
			}

			if ((CurrentPosition == (Position - 1)) && ((MyList->Next) != NULL))
			{
				RetElement = (MyList->Next)->Element;
				MyList->Next = (MyList->Next)->Next;
				free(MyList->Next);
			}
		}
	}

	return RetElement;
}

ELEMENT_TYPE_SINGLE_LIST SingleList_PopElement(MySingleList* MyList)
{
	ELEMENT_TYPE_SINGLE_LIST RetElement = 0;

	if (MyList != NULL)
	{
		MySingleList* CurrentNode = MyList;

		if (CurrentNode->Next != NULL)
		{
			while ((MyList->Next)->Next != NULL)
			{
				MyList = MyList->Next;
			}

			RetElement = ((MyList->Next)->Element);
			free(MyList->Next);
			MyList->Next = NULL;
		}
	}

	return RetElement;
}

void SingleList_Travese(MySingleList* MyList)
{
	if (MyList != NULL)
	{
		MyList = MyList->Next;

		if (MyList != NULL)
		{
			while (MyList != NULL)
			{
				printf_s("Element : %d\n", MyList->Element);
				MyList = MyList->Next;
			}
		}

		else
		{
			printf_s("Empty List!\n");
		}
	}

	else
	{
		printf_s("List is not created!\n");
	}
}

