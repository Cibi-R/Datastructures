#ifndef __STACK_DYNAMIC_H__
#define __STACK_DYNAMIC_H__

#define DYNAMIC_STACK_ELEMENT_TYPE unsigned int

/// <summary>
/// Structure to hold the data of a node
/// </summary>
typedef struct MyDynamicStack_t
{
	struct MyDynamicStack_t* Previous;
	DYNAMIC_STACK_ELEMENT_TYPE Element;
}MyDynamicStack;

/// <summary>
/// This function dynamically allocates memory for stack head node pointer and assigns the base address to HeadNode argument
/// </summary>
/// <param name="MyStack"></param>
/// <returns></returns>
extern unsigned char GetMyDynamicStack(MyDynamicStack** MyStack);

/// <summary>
/// This function push the data to the stack
/// </summary>
/// <param name="StackHead"></param>
/// <param name="ElementValue"></param>
/// <returns>0 on failure, 1 on success</returns>
extern unsigned char PushMyDynamicStack(MyDynamicStack* StackHead, DYNAMIC_STACK_ELEMENT_TYPE ElementValue);

/// <summary>
/// This function pops the data from the stack
/// </summary>
/// <param name="StackHead"></param>
/// <param name="ElementValue"></param>
/// <returns>0 on failure, 1 on success</returns>
extern unsigned char PopMyDynamicStack(MyDynamicStack* StackHead, DYNAMIC_STACK_ELEMENT_TYPE* ElementValue);

/// <summary>
/// This function returns the peek element of the stack, it will not remove the element
/// </summary>
/// <param name="StackHead"></param>
/// <param name="ElementValue"></param>
/// <returns>0 on failure, 1 on success</returns>
extern unsigned char PeekMyDynamicStack(MyDynamicStack* StackHead, DYNAMIC_STACK_ELEMENT_TYPE* ElementValue);

/// <summary>
/// This function traverse the stack
/// </summary>
/// <param name="StackHead"></param>
extern void TraverseMyDynamicStack(MyDynamicStack* StackHead);

#endif //__STACK_DYNAMIC_H__
