#ifndef __QUEUE_DYNAMIC_H__
#define __QUEUE_DYNAMIC_H__

#define DYNAMIC_QUEUE_ELEMENT int

/// <summary>
/// Structure to hold the data of a node
/// </summary>
typedef struct MyDynamicQueue_Tag
{
	struct MyDynamicQueue_Tag* next;
	DYNAMIC_QUEUE_ELEMENT QueueElement;
}MyDynamicQueue;

/// <summary>
/// This function dynamically allocates memory for queue head node pointer and assigns the base address to HeadNode argument
/// </summary>
/// <param name="HeadNode"></param>
/// <returns>0 on failure, 1 on success</returns>
unsigned char GetMyDynamicQueue(MyDynamicQueue* HeadNode);

/// <summary>
/// This function enqueue data to the queue
/// </summary>
/// <param name="HeadNode"></param>
/// <param name="Element"></param>
/// <returns>0 on failure, 1 on success</returns>
unsigned char EnQueueMyDynamicQueue(MyDynamicQueue* HeadNode, DYNAMIC_QUEUE_ELEMENT Element);

/// <summary>
/// This funtion dequeues data from the queue
/// </summary>
/// <param name="HeadNode"></param>
/// <param name="Element"></param>
/// <returns>0 on failure, 1 on success</returns>
unsigned char DeQueueMyDynamicQueue(MyDynamicQueue* HeadNode, DYNAMIC_QUEUE_ELEMENT* Element);

/// <summary>
/// This function returns the peek element of the queue, it will not remove the element
/// </summary>
/// <param name="HeadNode"></param>
/// <param name="Element"></param>
/// <returns>0 on failure, 1 on success</returns>
unsigned char PeekMyDynamicQueue(MyDynamicQueue* HeadNode, DYNAMIC_QUEUE_ELEMENT* Element);

/// <summary>
/// This function traverse the queue
/// </summary>
/// <param name="HeadNode"></param>
void TraverseMyDynamicQueue(MyDynamicQueue* HeadNode);

#endif //__QUEUE_DYNAMIC_H__