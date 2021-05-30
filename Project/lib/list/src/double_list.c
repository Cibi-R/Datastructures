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

	if ((NewNode != NULL) && (List != NULL))
	{
		if (List->Next == NULL)
		{
			List->Next = NewNode;

			NewNode->Previous = NULL;
		}
		else
		{
			MyDoubleList* TempNode = List->Next;

			while (TempNode->Next != NULL)
			{
				TempNode = TempNode->Next;
			}

			TempNode->Next = NewNode;

			NewNode->Previous = TempNode;
		}

		NewNode->Element = Element;
		NewNode->Next = NULL;

		List->Element++;
	}

	else
	{
		RetVal = 0;
	}

	return RetVal;
}

unsigned char DoubleList_PopElement(MyDoubleList* List, DOUBLE_LIST_ELEMENT_TYPE* Element)
{
	unsigned char RetVal = 1;

	if ((List != NULL) && (List->Next != NULL))
	{
		MyDoubleList* Temp = List->Next;

		if (Temp->Next == NULL)
		{
			List->Next = NULL;
		}

		else
		{
			while (Temp->Next != NULL)
			{
				Temp = Temp->Next;
			}

			(Temp->Previous)->Next = NULL;
		}

		*Element = Temp->Element;

		List->Element--;

		free(Temp);
	}
	else
	{
		RetVal = 0;
	}

	return RetVal;
}

unsigned char DoubleList_InsertElement(MyDoubleList* List, DOUBLE_LIST_ELEMENT_TYPE Element,uint32_t Position)
{
	unsigned char RetVal = 0;

	MyDoubleList* NewNode = (MyDoubleList*)malloc(sizeof(MyDoubleList));

	uint32_t CurrentPosition = 0;

	if ((NewNode != NULL) && (List != NULL))
	{
		/*< Start traversing from HeadNode pointer inorder to stop one node before the desired node. */
		MyDoubleList* TempNode = List;

		while ((TempNode->Next != NULL) && (CurrentPosition < Position))
		{
			TempNode = TempNode->Next;

			CurrentPosition++;
		}

		if (CurrentPosition == Position)
		{
			NewNode->Element = Element;
			NewNode->Next = TempNode->Next;

			if (0 == CurrentPosition)
			{
				/*< If the element position is 0, then the previous pointer is NULL */
				NewNode->Previous = NULL;
			}
			else
			{
				/*< Since we are stoping once node before the desired node, the previous node should the current temp node */
				NewNode->Previous = TempNode;
			}

			/*< Since we are stoping once node before the desired node, the next node of TempNode should be NewNode */
			TempNode->Next = NewNode;

			RetVal = 1;
		}
	}

	return RetVal;
}

unsigned char DoubleList_RemoveElement(MyDoubleList* List, DOUBLE_LIST_ELEMENT_TYPE* Element,  unsigned char Position)
{
	unsigned char RetVal = 0;

	uint32_t CurrentPosition = 0;

	if ((List != NULL) && (List->Next != NULL))
	{
		/*< Start traversing from HeadNode inorder. */
		MyDoubleList* TempNode = List->Next;

		while ((TempNode->Next != NULL) && (CurrentPosition < Position))
		{
			TempNode = TempNode->Next;

			CurrentPosition++;
		}

		if (CurrentPosition == Position)
		{
			*Element = TempNode->Element;

			if (TempNode->Previous == NULL)
			{
				/*< 0th element is getting removed so update the head pointer node */
				List->Next = TempNode->Next;

				if (List->Next != NULL)
				{
					/*< If the 0 element is present then update the previous pointer of 0th element. */
					(List->Next)->Previous = NULL;
				}
			}
			else
			{
				(TempNode->Previous)->Next = TempNode->Next;

				if (TempNode->Next != NULL)
				{
					(TempNode->Next)->Previous = TempNode->Previous;
				}
			}

			List->Element--;

			RetVal = 1;
		}
	}

	return RetVal;
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





