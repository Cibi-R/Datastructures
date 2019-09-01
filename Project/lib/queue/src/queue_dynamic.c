#include <include.h>
#include QUEUE_DYNAMIC_H

MyQueue* GetMyQueue(void)
{
	MyQueue* HeadNode;

	HeadNode = (MyQueue*)malloc(sizeof(MyQueue));

	if (HeadNode != NULL)
	{
		HeadNode->Element = 0;
		HeadNode->Next = NULL;
	}

	return HeadNode;
}

unsigned char MyQueue_Enqueue(MyQueue* HeadNode,QUEUE_ELEMENT_TYPE_DYNAMIC Element)
{

	MyQueue* NewNode = (MyQueue*)malloc(sizeof(MyQueue));

	if ((HeadNode != NULL) && (NewNode != NULL))
	{
		if (HeadNode->Next == NULL)
		{
			HeadNode->Next = NewNode;
		}

		else
		{
			MyQueue* TempNode;

			TempNode = HeadNode;

			while (TempNode->Next != NULL)
			{
				TempNode = TempNode->Next;
			}

			TempNode->Next = NewNode;
		}

		NewNode->Element = Element;

		NewNode->Next = NULL;

		return 1;
	}

	else
	{
		return 0;
	}
}

QUEUE_ELEMENT_TYPE_DYNAMIC MyQueue_Dequeue(MyQueue* HeadNode)
{
	QUEUE_ELEMENT_TYPE_DYNAMIC RetElement = 0;

	MyQueue* TempNode;

	if (!((HeadNode == NULL) || (HeadNode->Next == NULL)))
	{
		TempNode = HeadNode->Next;

		HeadNode->Next = TempNode->Next;

		RetElement = TempNode->Element;

		free(TempNode);
	}

	return RetElement;
}

QUEUE_ELEMENT_TYPE_DYNAMIC MyQueue_Peek(MyQueue* HeadNode)
{
	if (!((HeadNode == NULL) || (HeadNode->Next == NULL)))
	{
		return (MyQueue*)(HeadNode->Next)->Element;
	}

	else
	{
		return 0;
	}
}

void MyQueue_Traverse(MyQueue *HeadNode)
{
	MyQueue* TempNode;

	if (!((HeadNode == NULL) || (HeadNode->Next == NULL)))
	{
		TempNode = HeadNode;

		while (TempNode->Next != NULL)
		{
			TempNode = TempNode->Next;

			printf_s("%d\n", TempNode->Element);
		}
	}

	else
	{
		printf_s("Queue is empty!\n");
	}
}












