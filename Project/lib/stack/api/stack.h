#ifndef __STACK_H__
#define __STACK_H__

#define STACK_ELEMENT_TYPE  char
#define STACK_MAX_SIZE      100
#define STACK_EMPTY         -1

extern STACK_ELEMENT_TYPE Stack[STACK_MAX_SIZE];

extern int Stack_Push(STACK_ELEMENT_TYPE Element);

extern STACK_ELEMENT_TYPE Stack_Pop(void);

extern STACK_ELEMENT_TYPE Stack_Peek(void);

extern int Stack_Traverse(void);

#endif //__STACK_H__