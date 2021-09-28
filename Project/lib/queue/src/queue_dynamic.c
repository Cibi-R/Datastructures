#include <include.h>
#include QUEUE_DYNAMIC_H

unsigned char MyDynamicQueue_Create(MyDynamicQueue** HeadNode, uint16_t ElementSize)
{
	unsigned char retVal = 0;

	*HeadNode = (MyDynamicQueue*)malloc(sizeof(MyDynamicQueue));

	if (*HeadNode != NULL)
	{
		(*HeadNode)->next = NULL;

		/*< QueueElement member of the MyDynamicQueue is used to store size of the Queue eleement */
		(*HeadNode)->QueueElement = ElementSize;

		retVal = 1;
	}

	return retVal;
}

void MyDynamicQueue_Free(MyDynamicQueue* HeadNode)
{
	/*< dequeue all the element */
	while (MyDynamicQueue_DeQueue(HeadNode, NULL));
}

void MyDynamicQueue_Delete(MyDynamicQueue* HeadNode)
{

}

unsigned char MyDynamicQueue_EnQueue(MyDynamicQueue* HeadNode, void* QueueElement)
{
	unsigned char retVal = 0;

	MyDynamicQueue*  newNode = NULL;

	if (NULL != HeadNode)
	{
		newNode = (MyDynamicQueue*)malloc(sizeof(MyDynamicQueue));

		if (NULL != newNode)
		{
			char* queueData = (char*)malloc((unsigned int)HeadNode->QueueElement);

			if (NULL != queueData)
			{
				memcpy(queueData, QueueElement, (unsigned int)HeadNode->QueueElement);

				newNode->QueueElement = (void*) queueData;
				newNode->next = NULL;

				/* so far queue element has been created and value is stored to the queue element */

				if (NULL == HeadNode->next)
				{
					HeadNode->next = newNode;
				}
				else
				{
					MyDynamicQueue* tempNode = HeadNode->next;

					while (NULL != tempNode->next)
					{
						tempNode = tempNode->next;
					}

					tempNode->next = newNode;
				}

				retVal = 1;
			}
			else
			{
				/*< free memory for newNode if memory allocation fails for element */
				free(newNode);
			}
		}
	}

	return retVal;
}

unsigned char MyDynamicQueue_DeQueue(MyDynamicQueue* HeadNode, void* QueueElement)
{
	unsigned char retVal = 0;

	MyDynamicQueue* tempNode = NULL;

	if (HeadNode != NULL)
	{
		if (HeadNode->next != NULL)
		{
			/*< this logic will work even if there is only one node in the queue */
			tempNode = HeadNode->next;

			HeadNode->next = tempNode->next;

			if (NULL != QueueElement)
			{
				memcpy(QueueElement, tempNode->QueueElement, (unsigned int)HeadNode->QueueElement);
			}

			/*< free the memory allocated to the queue data element */
			free(tempNode->QueueElement);

			/*< free the memory allocated to the queue node */
			free(tempNode);

			retVal = 1;
		}
	}

	return retVal;
}

unsigned char MyDynamicQueue_Peek(MyDynamicQueue* HeadNode, void* QueueElement)
{
	unsigned char retVal = 0;

	MyDynamicQueue* tempNode;

	if (HeadNode != NULL)
	{
		if (HeadNode->next != NULL)
		{
			tempNode = HeadNode->next;

			memcpy(QueueElement, tempNode->QueueElement, (unsigned int)HeadNode->QueueElement);

			retVal = 1;
		}
	}

	return retVal;
}

void MyDynamicQueue_Traverse(MyDynamicQueue* HeadNode)
{
	MyDynamicQueue* tempNode = NULL;

	if (HeadNode != NULL)
	{
		if (HeadNode->next != NULL)
		{
			tempNode = HeadNode->next;

			do
			{
				printf("queue element : %d\n", *((unsigned int*)tempNode->QueueElement));

				tempNode = tempNode->next;

			} while (tempNode != NULL);
		}
	}
}












