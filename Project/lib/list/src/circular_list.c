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

				/*< tempNode points to the root node */
				tempNode = HeadNode;

				/*< if the list is empty, make the new node points to itself */
				if (NULL == tempNode->Next)
				{
					/*< make new node point to itself, create a circular list */
					newNode->Next = newNode;
				}
				else
				{
					/*< last node always points to the first node now, newNode is the last node */
					newNode->Next = (tempNode->Next)->Next;

					/*< make (last - 1)th node points to last node */
					(tempNode->Next)->Next = newNode;
				}

				HeadNode->Next = newNode;

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

	MyCircularSinglyList* lastNode = NULL;

	if (NULL != HeadNode)
	{
		if (NULL != HeadNode->Next)
		{
			tempNode = HeadNode->Next;

			while (tempNode->Next != HeadNode->Next)
			{
				tempNode = tempNode->Next;
			}

			lastNode = tempNode->Next;

			/*< copy the value */
			memcpy(Element, lastNode->Element, (uint16_t)HeadNode->Element);

			/*< if tempNode points to itself then only one node present in the list */
			if (tempNode->Next == tempNode)
			{
				HeadNode->Next = NULL;
			}
			else
			{
				/*< change the HeadNode pointer */
				HeadNode->Next = tempNode;

				/*< relink the last node, last node points to first node */
				tempNode->Next = lastNode->Next;
			}

			free(lastNode->Element);

			free(lastNode);

			retVal = 1;
		}
	}

	return retVal;
}

unsigned char MyCircularList_InsertElement(MyCircularSinglyList* HeadNode, void* Element, uint16_t Position)
{
	unsigned char retVal = 0;

	uint16_t currPosition = 0u;

	/*< list is not created */
	if (NULL != HeadNode)
	{
		/*< list is empty */
		if (NULL != HeadNode->Next)
		{
			
		}
	}

	return retVal;
}

unsigned char MyCircularList_RemoveElement(MyCircularSinglyList* HeadNode, void* Element, uint16_t Position)
{
	unsigned char retVal = 0;

	uint16_t currPosition = 0u;

	/*< list is not created */
	if (NULL != HeadNode)
	{
		/*< list is empty */
		if (NULL != HeadNode->Next)
		{
			
		}
	}
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