#include <include.h>
#include CIRCULAR_LIST_H

MyCircularSinglyList* GetCircularSinglyList(void)
{
	MyCircularSinglyList*NewList = (MyCircularSinglyList*)malloc(sizeof(MyCircularSinglyList));

	if (NewList != NULL)
	{
		NewList->Element = 0;
		NewList->Next = NULL;
	}

	return NewList;
}

unsigned char CircularList_PushElement(MyCircularSinglyList* List, CIRCULAR_SINGLY_LIST_ELEMENT_TYPE Element)
{
	unsigned char RetVal = 1;

	MyCircularSinglyList* NewNode = (MyCircularSinglyList*)malloc(sizeof(MyCircularSinglyList));

	MyCircularSinglyList* TempNode;

	/*< list is not created */
	if ((NewNode != NULL) && (List != NULL))
	{
		/*< TempNode is the last node in the list */
		TempNode = List->Next;

		/*< pointer to head node will point to the last node */
		List->Next = NewNode;

		if (TempNode == NULL)
		{
			/*< if circular singly list has one node, the node should be pointing to itself */
			NewNode->Next = NewNode;
		}

		else
		{
			NewNode->Next = TempNode->Next;

			TempNode->Next = NewNode;
		}

		/*< store element */
		NewNode->Element = Element;

		RetVal = 1;
	}

	return RetVal;
}

unsigned char CircularList_PopElement(MyCircularSinglyList* List, CIRCULAR_SINGLY_LIST_ELEMENT_TYPE* Element)
{
	unsigned char RetVal = 0;

	MyCircularSinglyList* TempNode = List->Next;

	if (TempNode != NULL)
	{
		TempNode = TempNode->Next;

		while (TempNode->Next != List->Next)
		{
			TempNode = TempNode->Next;
		}

		*Element = (TempNode->Next)->Element;

		/*< one node is present in the list */
		if (TempNode->Next == List->Next)
		{
			free(TempNode->Next);

			/*< circular singly list is empty */
			List->Next = NULL;
		}
		else
		{
			/*< store the last node next address to previous node's next address */
			TempNode->Next = (TempNode->Next)->Next;

			/*< delete the last node */
			free(List->Next);

			/*< make the head node to point to last node */
			List->Next = TempNode;
		}

		RetVal = 1;
	}

	return RetVal;
}

unsigned char CircularList_InsertElement(MyCircularSinglyList* List, CIRCULAR_SINGLY_LIST_ELEMENT_TYPE Element, uint32_t Position)
{
#if 0
	unsigned char RetVal = 0;

	uint32_t CurrentPosition = 0;

	MyCircularSinglyList* TempNode;

	MyCircularSinglyList* NewNode;

	MyCircularSinglyList* FirstNode;

	if (List != NULL)
	{
		if ((List->Next == NULL) && (Position == 0))
		{
			CircularList_PushElement(List, Element);

			RetVal = 1;
		}

		else if (List->Next != NULL)
		{
			NewNode = (MyCircularSinglyList*)malloc(sizeof(MyCircularSinglyList));

			if (NewNode != NULL)
			{
				FirstNode = (List->Next)->Next;

				TempNode = FirstNode;

				while ((TempNode->Next != FirstNode) && (CurrentPosition < Position))
				{
					CurrentPosition++;

					TempNode = TempNode->Next;
				}

				if (CurrentPosition == Position)
				{
					if (CurrentPosition == 0)
					{
						NewNode->Next = List->Next->Next;

						List->Next->Next = NewNode;
					}
				}
				else
				{
					free(NewNode);
				}
			}
		}
	}

	return RetVal;
#endif 
}


unsigned char CircularList_RemoveElement(MyCircularSinglyList* List, CIRCULAR_SINGLY_LIST_ELEMENT_TYPE* Element, uint32_t Position)
{
	unsigned char RetVal = 0;

	MyCircularSinglyList* TempNode = List;

	uint32_t CurrentPosition = 0;

	if (TempNode != NULL)
	{
		if (TempNode->Next != NULL)
		{
			while ((((TempNode->Next)->Next) != (List->Next)) && (CurrentPosition < Position))
			{
				TempNode = TempNode->Next;
			}

			if (CurrentPosition == Position)
			{
				*Element = (TempNode->Next)->Element;

				if ((TempNode->Next)->Next == List->Next)
				{
					free(TempNode->Next);

					TempNode->Next = NULL;
				}

				else
				{
					MyCircularSinglyList* DeleteNode = TempNode->Next;

					TempNode->Next = (TempNode->Next)->Next;

					free(DeleteNode);
				}

				RetVal = 1;
			}
		}
	}
}

void CircularList_Traverse(MyCircularSinglyList* List)
{
	if (List == NULL)
	{
		printf_s("Circular singly list is not created!\n");
	}

	else if (List->Next == NULL)
	{
		printf_s("Circular singly list is empty!\n");
	}

	else 
	{
		MyCircularSinglyList* Temp = (List->Next)->Next;

		do
		{
			printf_s("Element : %d\n", Temp->Element);

			Temp = Temp->Next;

			/*printf_s("Address 1 : %d\n", Temp);
			printf_s("Address 2 : %d\n", List->Next);*/
		}while(Temp != (List->Next)->Next);

		printf_s("Traverse completed!\n");
	}
}