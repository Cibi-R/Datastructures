#include <include.h>
#include QUEUE_DYNAMIC_H

unsigned char GetMyDynamicQueue(MyDynamicQueue** HeadNode)
{
	unsigned char retval = 0;

	*HeadNode = (MyDynamicQueue*)malloc(sizeof(MyDynamicQueue));

	if (*HeadNode != NULL)
	{
		(*HeadNode)->next = NULL;
		(*HeadNode)->QueueElement = 0;

		retval = 1;
	}

	return retval;
}

unsigned char EnQueueMyDynamicQueue(MyDynamicQueue* HeadNode, DYNAMIC_QUEUE_ELEMENT Element)
{
	unsigned char retval = 0;

	MyDynamicQueue* TempNode = NULL;
	MyDynamicQueue* NewNode = NULL;

	NewNode = (MyDynamicQueue*)malloc(sizeof(MyDynamicQueue));

	if ((HeadNode != NULL) && (NewNode != NULL))
	{
		/*< the logic will work even when the queue is empty, In queue the headnode pointer will be pointing to the first node */
		TempNode = HeadNode;

		while (TempNode->next != NULL)
		{
			TempNode = TempNode->next;
		}

		TempNode->next = NewNode;

		NewNode->QueueElement = Element;
		NewNode->next = NULL;

		retval = 1;
	}

	return retval;
}

unsigned char DeQueueMyDynamicQueue(MyDynamicQueue* HeadNode, DYNAMIC_QUEUE_ELEMENT* Element)
{
	unsigned char retval = 0;

	MyDynamicQueue* TempNode;

	if (HeadNode != NULL)
	{
		if (HeadNode->next != NULL)
		{
			/*< this logic will work even if there is only one node in the queue */
			TempNode = HeadNode->next;

			HeadNode->next = TempNode->next;

			*Element = TempNode->QueueElement;

			free(TempNode);

			retval = 1;
		}
	}

	return retval;
}

unsigned char PeekMyDynamicQueue(MyDynamicQueue* HeadNode, DYNAMIC_QUEUE_ELEMENT* Element)
{
	unsigned char retval = 0;

	if (HeadNode != NULL)
	{
		if (HeadNode->next != NULL)
		{
			*Element = (HeadNode->next)->QueueElement;

			retval = 1;
		}
	}

	return retval;
}

void TraverseMyDynamicQueue(MyDynamicQueue* HeadNode)
{
	MyDynamicQueue* TempNode = NULL;

	if (HeadNode != NULL)
	{
		if (HeadNode->next != NULL)
		{
			TempNode = HeadNode->next;

			do
			{
				printf("Element : %d\n", TempNode->QueueElement);

				TempNode = TempNode->next;
			} while (TempNode != NULL);
		}
	}
}












