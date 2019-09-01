#ifndef __STACK_DYNAMIC_H__
#define __STACK_DYNAMIC_H__

#define STACK_ELEMENT_TYPE_DYNAMIC unsigned int

typedef struct _MyStack
{
	STACK_ELEMENT_TYPE_DYNAMIC Element;
	struct _MinStack* Next;
} MyStack;

extern unsigned int Stack_Len;

extern MyStack* Get_MyStack(void);

extern void Push_MyStack(MyStack* StackHead, STACK_ELEMENT_TYPE_DYNAMIC x);

extern STACK_ELEMENT_TYPE_DYNAMIC Pop_MyStack(MyStack* StackHead);

extern STACK_ELEMENT_TYPE_DYNAMIC Peek_MyStack(MyStack* StackHead);

extern void Traverse_MyStack(MyStack* StackHead);

extern STACK_ELEMENT_TYPE_DYNAMIC GetSize_MyStack(MyStack* StackHead);

extern void Delete_MyStack(MyStack* StackHead);

#endif //__STACK_DYNAMIC_H__
