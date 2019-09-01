#ifndef __QUEUE_DYNAMIC_H__
#define __QUEUE_DYNAMIC_H__

#define QUEUE_ELEMENT_TYPE_DYNAMIC int

typedef struct _MyQueue
{
	QUEUE_ELEMENT_TYPE_DYNAMIC Element;
	struct _MyQueue *Next;
}MyQueue;

extern MyQueue* GetMyQueue(void);

extern unsigned char MyQueue_Enqueue(MyQueue* HeadNode, QUEUE_ELEMENT_TYPE_DYNAMIC Element);

extern QUEUE_ELEMENT_TYPE_DYNAMIC MyQueue_Dequeue(MyQueue* HeadNode);

extern void MyQueue_Traverse(MyQueue* HeadNode);

#endif