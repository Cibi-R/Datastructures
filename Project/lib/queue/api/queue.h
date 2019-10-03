#ifndef __QUEUE_H__
#define __QUEUE_H__

/*********************************************************************************************************************
 *							                       Preprocessor Constants
 ********************************************************************************************************************/

#define QUEUE_ELEMENT_TYPE  unsigned char
#define QUEUE_MAX_SIZE      10
#define QUEUE_EMPTY         -1 

 /*********************************************************************************************************************
  *							                       Functions Declarations
  ********************************************************************************************************************/

  /*
   *  @brief : This function is used to enqueue an element to a list.
   *  @param : void.
   *  @return: MySingleList. dynamically created Pointer to a head node.
   */

extern unsigned char Enqueue(QUEUE_ELEMENT_TYPE Element);

extern QUEUE_ELEMENT_TYPE Dequeue(void);

extern QUEUE_ELEMENT_TYPE Queue_Peek(void);

extern void Queue_Traverse(void);

#endif //__STACK_H__
