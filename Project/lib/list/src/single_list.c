#include <include.h>
#include SINGLE_LIST_H


unsigned char MySingleList_Create(MySingleList** RootNode, uint16_t ElementSize)
{
	unsigned char retVal = 1;

	*RootNode = (MySingleList*)malloc(sizeof(MySingleList));

	if (*RootNode != NULL)
	{
		/*< make list empty */
		(*RootNode)->Next = NULL;

#ifdef DYNAMICALLY_ALLOCATE_MEMORY_FOR_ELEMENT_IN_ROOT
		(*RootNode)->Element = (void*)malloc(sizeof(uint16_t));
		if (NULL == (*RootNode)->Element)
		{
			retVal = 0;
		}
		else
		{
			*((uint16_t*)(*RootNode)->Element) = ElementSize;
		}
#else
		/* store the size of the node data to Element memer of the MySingleList HeadNode */
		(*RootNode)->Element = (void*)ElementSize;
#endif
	}
	else
	{
		retVal = 0;
	}
	
	return retVal;
}

unsigned char MySingleList_PushElement(MySingleList* RootNode, void* Element)
{
	unsigned char retVal = 0;

	if (NULL != RootNode)
	{
		MySingleList* newNode = (MySingleList*)malloc(sizeof(MySingleList));

		if (NULL != newNode)
		{
#ifdef DYNAMICALLY_ALLOCATE_MEMORY_FOR_ELEMENT_IN_ROOT
			newNode->Element = (void*)malloc(*((uint16_t*)RootNode->Element));
#else
			/*< allocate memory for the list element */
			newNode->Element = (void*)malloc((unsigned int)RootNode->Element);
#endif

			if (NULL != newNode->Element)
			{
#ifdef DYNAMICALLY_ALLOCATE_MEMORY_FOR_ELEMENT_IN_ROOT
				memcpy(newNode->Element, Element, *((uint16_t*)RootNode->Element));
#else
				/*< copy the element to be pushed */
				memcpy(newNode->Element, Element, (unsigned int)RootNode->Element);
#endif
				/*< mark the next of new node as null */
				newNode->Next = NULL;

				MySingleList* tempNode = RootNode;

				while (NULL != tempNode->Next)
				{
					tempNode = tempNode->Next;
				}

				tempNode->Next = newNode;

				retVal = 1;
			}
			else
			{
				/*< delete the created node, if memory allocation fails for the element of a node */
				free(newNode);
			}
		}
	}
}

unsigned char MySingleList_PopElement(MySingleList* RootNode, void* Element)
{
	unsigned char retVal = 0;

	MySingleList* tempNode = NULL;

	if (NULL != RootNode)
	{
		if (NULL != RootNode->Next)
		{
			tempNode = RootNode;

			while (NULL != (tempNode->Next)->Next)
			{
				tempNode = tempNode->Next;
			}
			/*< we are at last element */

#ifdef DYNAMICALLY_ALLOCATE_MEMORY_FOR_ELEMENT_IN_ROOT
			memcpy(Element, tempNode->Next->Element, *((uint16_t*)RootNode->Element));
#else
			/*< copy the element to be pushed */
			memcpy(Element, tempNode->Next->Element, (unsigned int)RootNode->Element);
#endif

			/*< free the memory for the element */
			free(tempNode->Next->Element);

			/*< free the memory for the node */
			free(tempNode->Next);

			/*< make the next as null, make it last element */
			tempNode->Next = NULL;

			retVal = 1;
		}
	}

	return retVal;
}

unsigned char MySingleList_InsertElement(MySingleList* RootNode, void* Element, uint16_t Position)
{
	unsigned char retVal = 0;

	uint16_t currentPosition = 0;

	MySingleList* tempNode = NULL;

	if (NULL != RootNode)
	{
		tempNode = RootNode;

		while ((NULL != tempNode->Next) && (currentPosition < Position))
		{
			tempNode = tempNode->Next;

			currentPosition++;
		}

		if (Position == currentPosition)
		{
			MySingleList* newNode = (MySingleList*)malloc(sizeof(MySingleList));

			if (NULL != newNode)
			{
#ifdef DYNAMICALLY_ALLOCATE_MEMORY_FOR_ELEMENT_IN_ROOT
				newNode->Element = (void*)malloc((unsigned int)RootNode->Element);
#else
				newNode->Element = (void*)malloc((unsigned int)RootNode->Element);
#endif

				if (NULL != newNode->Element)
				{
					/*< copy the element to the newly created node */
#ifdef DYNAMICALLY_ALLOCATE_MEMORY_FOR_ELEMENT_IN_ROOT
					memcpy(newNode->Element, Element, *((uint16_t*)RootNode->Element));
#else
					/*< copy the element to be pushed */
					memcpy((newNode->Element, Element, (unsigned int)RootNode->Element);
#endif
					/*< insert the newly created node */
					newNode->Next = tempNode->Next;
					
					tempNode->Next = newNode;

					retVal = 1;
				}
				else
				{
					free(newNode);
				}
			}
		}
	}

	return retVal;
}

unsigned char MySingleList_RemoveElement(MySingleList* RootNode, void* Element, uint16_t Position)
{
	unsigned char retVal = 0;

	uint16_t currentPosition = 0;

	if (NULL != RootNode)
	{
		MySingleList* tempNode = RootNode;

		while ((tempNode->Next != NULL) && (currentPosition < Position))
		{
			tempNode = tempNode->Next;

			currentPosition++;
		}

		if ((currentPosition == Position) && (NULL != tempNode->Next))
		{
			MySingleList* linkNode = NULL;

#ifdef DYNAMICALLY_ALLOCATE_MEMORY_FOR_ELEMENT_IN_ROOT
			memcpy(Element, tempNode->Next->Element, *((uint16_t*)RootNode->Element));
#else
			/*< copy the element to be pushed */
			memcpy(Element, tempNode->Next->Element, (unsigned int)RootNode->Element);
#endif

			linkNode = tempNode->Next->Next;

			/*< free the memory for the element */
			free(tempNode->Next->Element);

			/*< free the memory for the node */
			free(tempNode->Next);

			/*< relink the list */
			tempNode->Next = linkNode;
		}
	}

	return retVal;
}

unsigned char MySingleList_GetElement(MySingleList* RootNode, void* Element, uint16_t Position)
{
	unsigned char retVal = 0;

	uint16_t currentPosition = 0;

	if (NULL != RootNode)
	{
		if (NULL != RootNode->Next)
		{
			MySingleList* tempNode = RootNode->Next;

			while ((tempNode->Next != NULL) && (currentPosition < Position))
			{
				tempNode = tempNode->Next;

				currentPosition++;
			}

			if (currentPosition == Position)
			{
				memcpy(Element, tempNode->Element, (unsigned int)RootNode->Element);

				retVal = 1;
			}
		}
	}

	return retVal;
}

void MySingleList_Traverse(MySingleList* MyList)
{
	if (NULL != MyList)
	{
		if (NULL != MyList->Next)
		{
			MyList = MyList->Next;

			do
			{
				printf("list element : %d\n", *((unsigned int*)MyList->Element));

				MyList = MyList->Next;
			} while (NULL != MyList);
		}
		else
		{
			printf("list is empty!\n");
		}
	}
	else
	{
		printf("list not created!\n");
	}
}

