#include <include.h>
#include CIRCULAR_LIST_H

unsigned char MyCircularList_Create(MyCircularSinglyList** HeadNode, uint16_t Size)
{
	unsigned char retVal = 1;

	*HeadNode = (MyCircularSinglyList*)malloc(sizeof(MyCircularSinglyList));

	if (*HeadNode != NULL)
	{
		(*HeadNode)->Next = NULL;

		(*HeadNode)->Element = (void*)Size;
	}
	else
	{
		retVal = 0;
	}

	return retVal;
}

unsigned char MyCircularList_PushElement(MyCircularSinglyList* HeadNode, void* Element)
{
	unsigned char retVal = 0;

	MyCircularSinglyList* tempNode = NULL;

	/*< list is not created */
	if (NULL != HeadNode)
	{
		MyCircularSinglyList* newNode = (MyCircularSinglyList*) malloc(sizeof(MyCircularSinglyList));

		if (NULL != newNode)
		{
			newNode->Element = (void*) malloc((uint16_t)HeadNode->Element);

			if (NULL != newNode->Element)
			{
				/*< copy th element */
				memcpy(newNode->Element, Element, (uint16_t)HeadNode->Element);

				tempNode = HeadNode;

				/*< root node point to the first inserted node of the list */
				if (NULL == tempNode->Next)
				{
					/*< list is empty, make root node point to the newnode */
					HeadNode->Next = newNode;

					/*< make new node point to itself, create a circular list */
					newNode->Next = newNode;
				}
				/*< list is not empty */
				else
				{
					/*< point to the first node */
					tempNode = tempNode->Next;

					/*< last node will point to the first node so, run the loop till it points the first node */
					while (HeadNode->Next != tempNode->Next)
					{
						tempNode = tempNode->Next;
					}

					/*< link the node */
					tempNode->Next = newNode;

					/*< make it circular by linking the last node to first node */
					newNode->Next = HeadNode->Next;
				}

				retVal = 1;
			}
			else
			{
				free(newNode);
			}
		}
	}

	return retVal;
}

unsigned char MyCircularList_PopElement(MyCircularSinglyList* HeadNode, void* Element)
{
	unsigned char retVal = 0;

	MyCircularSinglyList* tempNode = NULL;

	if (NULL != HeadNode)
	{
		if (NULL != HeadNode->Next)
		{
			tempNode = HeadNode;

			if (tempNode->Next == (tempNode->Next)->Next)
			{
				/*< in the next instruction we are setting this value to NULL */
				tempNode = HeadNode->Next;

				/*< only one element present inside the list */
				HeadNode->Next = NULL;
			}
			else
			{
				while (HeadNode->Next != (tempNode->Next)->Next)
				{
					tempNode = tempNode->Next;
				}
			}

			printf_s("value : %d\n", *((unsigned int*)(tempNode->Next)->Element));

			memcpy(Element, (tempNode->Next)->Element, (uint16_t)HeadNode->Element);

			free(tempNode->Next->Element);

			free(tempNode->Next);

			/*< point to the first node */
			tempNode->Next = HeadNode->Next;

			retVal = 1;
		}
	}

	return retVal;
}

unsigned char MyCircularList_InsertElement(MyCircularSinglyList* HeadNode, void* Element, uint16_t Position)
{
	uint16_t currPosition = 0;

	if (NULL != HeadNode)
	{
		if (NULL != HeadNode->Next)
		{
			MyCircularSinglyList* tempNode = HeadNode;

			while ((((tempNode->Next)->Next) != HeadNode->Next) && (Position < currPosition))
			{
				tempNode = tempNode->Next;

				currPosition++;
			}

			if (currPosition == Position)
			{
				MyCircularSinglyList* newNode = (MyCircularSinglyList*) malloc(sizeof(MyCircularSinglyList));

				if (NULL != newNode)
				{
					newNode->Element = (void*)malloc((uint16_t)HeadNode->Element);

					if (NULL != newNode->Element)
					{
						if (0u == Position)
						{
							MyCircularSinglyList* lastNode = HeadNode;

							/*< if the position is 0 we should alter the next of the last element */
							while (((lastNode->Next)->Next) != HeadNode->Next)
							{
								lastNode = lastNode->Next;

								currPosition++;
							}

							lastNode->Next->Next = newNode;
						}
						
						memcpy(newNode->Element, Element, (uint16_t)HeadNode->Element);

						newNode->Next = tempNode->Next;

						tempNode->Next = newNode->Next;
					}
					else
					{
						free(newNode);
					}
				}
			}
		}
	}
}

unsigned char MyCircularList_RemoveElement(MyCircularSinglyList* List, void* Element, uint16_t Position)
{

}

unsigned char MyCiruclarList_Traverse(MyCircularSinglyList* HeadNode)
{
	if (HeadNode == NULL)
	{
		printf_s("Circular singly list is not created!\n");
	}

	else if (HeadNode->Next == NULL)
	{
		printf_s("Circular singly list is empty!\n");
	}

	else 
	{
		MyCircularSinglyList* Temp = HeadNode->Next;

		do
		{
			printf_s("Element : %d\n", *((unsigned int*)(Temp->Element)));

			Temp = Temp->Next;

			/*printf_s("Address 1 : %d\n", Temp);
			printf_s("Address 2 : %d\n", List->Next);*/
		}while(Temp != HeadNode->Next);
	}
}