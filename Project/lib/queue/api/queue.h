#ifndef __QUEUE_H__
#define __QUEUE_H__

#define QUEUE_ELEMENT_TYPE  unsigned char
#define QUEUE_MAX_SIZE      10
#define QUEUE_EMPTY         -1 

extern unsigned char Enqueue(QUEUE_ELEMENT_TYPE Element);

extern QUEUE_ELEMENT_TYPE Dequeue(void);

extern QUEUE_ELEMENT_TYPE Queue_Peek(void);

extern void Queue_Traverse(void);

#endif //__STACK_H__
