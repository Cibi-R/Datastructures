#ifndef __QUEUE_DYNAMIC_H__
#define __QUEUE_DYNAMIC_H__

#define DYNAMIC_QUEUE_ELEMENT int

/// <summary>
/// Structure to hold the data of a node
/// </summary>
typedef struct MyDynamicQueue_Tag
{
	struct MyDynamicQueue_Tag* next;
	void* QueueElement;
}MyDynamicQueue;

/// <summary>
/// this function dynamically allocates memory for queue's root node pointer and assigns the next pointer to null (marking it as empty)
/// </summary>
/// <param name="HeadNode - pointer to the head node"></param>
/// <param name="ElementSize - size of the queue element"></param>
/// <returns>0 on failure, 1 on success</returns>
extern unsigned char MyDynamicQueue_Create(MyDynamicQueue** HeadNode, uint16_t ElementSize);

/// <summary>
/// this function is used to enqueue the data to the queue
/// </summary>
/// <param name="HeadNode - Pointer to the Dynamic queue" ></param>
/// <param name="QueueElement - Pointer to the data where enqueued data will be stored"></param>
/// <returns>0 on failure, 1 on success</returns>
extern unsigned char MyDynamicQueue_EnQueue(MyDynamicQueue* HeadNode, void* QueueElement);

/// <summary>
/// this function is used to dequeue the data from the queue
/// </summary>
/// <param name="HeadNode - Pointer to the Dynamic queue"></param>
/// <param name="QueueElement - Pointer to the data where dequeued data will be stored"></param>
/// <returns>0 on failure, 1 on success</returns>
extern unsigned char MyDynamicQueue_DeQueue(MyDynamicQueue* HeadNode, void* QueueElement);

/// <summary>
/// This function returns the peek element of the queue, it will not remove the element
/// </summary>
/// <param name="HeadNode - Pointer to the Dynamic queue"></param>
/// <param name="QueueElement - Pointer to the data where peek element will be stored"></param>
/// <returns>0 on failure, 1 on success</returns>
extern unsigned char MyDynamicQueue_Peek(MyDynamicQueue* HeadNode, void* QueueElement);

/// <summary>
/// This function traverse the queue
/// </summary>
/// <param name="HeadNode"></param>
extern void MyDynamicQueue_Traverse(MyDynamicQueue* HeadNode);

#endif //__QUEUE_DYNAMIC_H__