#include <include.h>
#include STACK_DYNAMIC_H


unsigned char MyDynamicStack_Create(MyDynamicStack** HeadNode, uint16_t ElementSize)
{
	unsigned char retVal = 0;

	*HeadNode = (MyDynamicStack*)malloc(sizeof(MyDynamicStack));

	if (NULL != HeadNode)
	{
		(*HeadNode)->Previous = NULL;

#if defined(DYNAMICALLY_ALLOCATE_MEMORY_FOR_ELEMENT_IN_ROOT)

		(*HeadNode)->Element = (void*)malloc(sizeof(uint16_t));

		if (NULL != (*HeadNode)->Element)
		{
			*((uint16_t*)((*HeadNode)->Element)) = ElementSize;
		}
		else
		{
			free(*HeadNode);

			*HeadNode = NULL;
		}
#else
		/*< store the size of the stack element to "Element" member of the dynamic stack Head pointer, even though it is
	void pointer variable we will store the eleemnt size, and we will access the "Element" pointer variable of the
	HeadNode as a integer value */
		(*HeadNode)->Element = (void*)ElementSize;
#endif

		retVal = 1;
	}

	return retVal;
}

unsigned char MyDynamicStack_Push(MyDynamicStack* HeadNode, void* StackElement)
{
	unsigned char retVal = 0;

	MyDynamicStack* newNode = NULL;

	if (HeadNode != NULL)
	{
		newNode = (MyDynamicStack*)malloc(sizeof(MyDynamicStack));

		if (NULL != newNode)
		{
#if defined(DYNAMICALLY_ALLOCATE_MEMORY_FOR_ELEMENT_IN_ROOT)
			newNode->Element = (void*)malloc(*((uint16_t*)HeadNode->Element));
#else
			newNode->Element = (void*)malloc((unsigned int)HeadNode->Element);
#endif
			if (NULL != newNode->Element)
			{
				/*< store the element value */
#if defined(DYNAMICALLY_ALLOCATE_MEMORY_FOR_ELEMENT_IN_ROOT)
				memcpy(newNode->Element, StackElement, *((uint16_t*)HeadNode->Element));
#else
				memcpy(newNode->Element, StackElement, (unsigned int)HeadNode->Element);
#endif

				/*< HeadNode->Previous will always point to the top of the stack, it could be null or valid element */
				newNode->Previous = HeadNode->Previous;

				/*< newly created node is the top of the stack, so store the new node to HeadNode->Previous */
				HeadNode->Previous = newNode;

				retVal = 1;
			}
			else
			{
				/*< if free fails while createing Element clear the NewNode pointer else it will result in memory leak */
				free(newNode);
			}
		}
	}

	return retVal;
}

unsigned char MyDynamicStack_Pop(MyDynamicStack* HeadNode, void* StackElement)
{
	unsigned char retVal = 0;

	MyDynamicStack* tempNode = NULL;

	if (HeadNode != NULL)
	{
		/*< HeadNode->Previous will always point to the top of the stack */
		tempNode = HeadNode->Previous;

		if (NULL != tempNode)
		{
			/*< tempNode->Previous will be the next top element of the stack */
			HeadNode->Previous = tempNode->Previous;

			if (NULL != StackElement)
			{
				/*< copy the top element of the stack */
#if defined(DYNAMICALLY_ALLOCATE_MEMORY_FOR_ELEMENT_IN_ROOT)
				uint16_t stackElementSize = *((uint16_t*)HeadNode->Element);
				memcpy(StackElement, tempNode->Element, *((uint16_t*)HeadNode->Element));
#else
				memcpy(StackElement, tempNode->Element, (unsigned int)HeadNode->Element);
#endif
			}

			/*< free the stack element */
			free(tempNode->Element);

			/*< free the stack node */
			free(tempNode);

			retVal = 1;
		}
	}

	return retVal;
}


unsigned char MyDynamicStack_Peek(MyDynamicStack* HeadNode, void* StackElement)
{
	unsigned char retVal = 0;

	if (HeadNode != NULL)
	{
		/*< check whether the stack is empty */
		if (HeadNode->Previous != NULL)
		{
#if defined(DYNAMICALLY_ALLOCATE_MEMORY_FOR_ELEMENT_IN_ROOT)
			memcpy(StackElement, HeadNode->Previous->Element, *((uint16_t*)HeadNode->Element));
#else
			memcpy(StackElement, HeadNode->Previous->Element, (unsigned int)HeadNode->Element);
#endif

			retVal = 1;
		}
	}

	return retVal;
}

unsigned char MyDynamicStack_Is_Empty(MyDynamicStack* HeadNode)
{
	unsigned char retVal = 0;

	if (HeadNode)
	{
		if (NULL == HeadNode->Previous)
		{
			retVal = 1;
		}
	}

	return retVal;
}

uint16_t MyDynamicStack_Length(MyDynamicStack* HeadNode)
{
	uint16_t stackLength = 0;

	if (NULL != HeadNode)
	{
		if (NULL != HeadNode->Previous)
		{
			do
			{
				stackLength++;

				HeadNode = HeadNode->Previous;

			} while (HeadNode != NULL);
		}
	}

	return stackLength;
}

void MyDynamicStack_Traverse(MyDynamicStack* HeadNode)
{
	unsigned int tempValue = 0;

	MyDynamicStack* tempNode = NULL;

	if (HeadNode != NULL)
	{
		tempNode = HeadNode->Previous;

		if (tempNode != NULL)
		{
			do
			{

#if defined(DYNAMICALLY_ALLOCATE_MEMORY_FOR_ELEMENT_IN_ROOT)
				memcpy(&tempValue, tempNode->Element, *((uint16_t*)HeadNode->Element));
#else
				memcpy(&tempValue, tempNode->Element, (unsigned int)HeadNode->Element);
#endif

				printf("stack element : %c\n", tempValue);

				tempNode = tempNode->Previous;

			} while (tempNode != NULL);
		}
		else
		{
			printf("stack is empty\n");
		}
	}
	else
	{
		printf("stack is not created\n");
	}
}

      