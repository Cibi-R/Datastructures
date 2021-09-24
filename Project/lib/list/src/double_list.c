#include <include.h>
#include DOUBLE_LIST_H

unsigned char MyDoubleList_Create(MyDoubleList** RootNode, uint16_t ElementSize)
{
	unsigned char retVal = 0;

	*RootNode = (MyDoubleList*)malloc(sizeof(MyDoubleList));

	if (*RootNode != NULL)
	{
		(*RootNode)->Previous = NULL;
		(*RootNode)->Element = (uint16_t)ElementSize;
		(*RootNode)->Next     = NULL;

		retVal = 1;
	}

	return retVal;
}

unsigned char MyDoubleList_PushElement(MyDoubleList* RootNode, void* Element)
{
	unsigned char retVal = 0;

	MyDoubleList* tempNode = NULL;

	MyDoubleList* newNode = NULL;

	if (NULL != RootNode)
	{
		newNode = (MyDoubleList*)malloc(sizeof(MyDoubleList));

		if (NULL != newNode)
		{
			newNode->Element = (void*)malloc((uint16_t)RootNode->Element);

			if (NULL != newNode->Element)
			{
				/*< copy the element */
				memcpy(newNode->Element, Element, (uint16_t)RootNode->Element);

				/*< point to head node */
				tempNode = RootNode;

				/*< list is empty so, first node previous pointer should point to NULL */
				if (NULL == tempNode->Next)
				{
					newNode->Previous = NULL;	
				}
				else
				{
					while (NULL != tempNode->Next)
					{
						tempNode = tempNode->Next;
					}

					/*< link the new node */
					tempNode->Next = newNode;

					/*< link the new node with existing last node */
					newNode->Previous = tempNode;

					/*< Head should point to last node of the list */
					RootNode->Next = newNode;
				}

				tempNode->Next = newNode;

				newNode->Next = NULL;

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

unsigned char MyDoubleList_PopElement(MyDoubleList* RootNode, void* Element)
{
	unsigned char retVal = 0;

	MyDoubleList* tempNode = NULL;

	if (NULL != RootNode->Next)
	{
		tempNode = RootNode->Next;

		if (NULL != tempNode)
		{
			/*< make the root node point to new last node */
			RootNode->Next = tempNode->Previous;

			memcpy(Element, tempNode->Element, (uint16_t)RootNode->Element);

			free(tempNode->Element);

			free(tempNode);

			retVal = 1;
		}
	}

	return retVal;
}

unsigned char MyDoubleList_InsertElement(MyDoubleList* RootNode, void* Element, uint16_t Position)
{
	unsigned char retVal = 0;

	if (NULL != RootNode)
	{
		MyDoubleList* tempNode = RootNode->Next;
	}
}

unsigned char MyDoubleList_RemoveElement(MyDoubleList* RootNode, void* Element, uint16_t Position)
{

}

unsigned char MyDoubleList_GetElement(MyDoubleList* RootNode, void* Element, uint16_t Position)
{

}

void MyDoubleList_Traverse(MyDoubleList* List)
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
				printf_s("Element : %d\n", *((unsigned int*)List->Element));
				List = List->Previous;
			} while (List != NULL);
		}
	}

	else
	{
		printf_s("Double list is not created!\n");
	}
}





