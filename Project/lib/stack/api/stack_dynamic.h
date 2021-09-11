#ifndef __STACK_DYNAMIC_H__
#define __STACK_DYNAMIC_H__

#define DYNAMIC_STACK_ELEMENT_TYPE unsigned int

/// <summary>
/// Structure to hold the data of a node
/// </summary>
typedef struct MyDynamicStack_Tag
{
	struct MyDynamicStack_Tag* Previous;
	void* Element;
}MyDynamicStack;

/// <summary>
/// This function dynamically allocates memory for stack head node pointer and assigns the base address to HeadNode argument
/// </summary>
/// <param name="MyStack"></param>
/// <returns></returns>
extern unsigned char MyDynamicQueue_Create(MyDynamicStack** HeadNode, uint16_t ElementSize);

/// <summary>
/// This function is used to push the data to the stack
/// </summary>
/// <param name="MyDynamicStack - pointer to the dynamic stack"></param>
/// <param name="void* - pointer to the data to be pushed"></param>
/// <returns>0 on failure, 1 on success</returns>
extern unsigned char MyDynamicStack_Push(MyDynamicStack* HeadNode, void* StackElement);

/// <summary>
/// This function is used to pop the data from the stack
/// </summary>
/// <param name="MyDynamicStack - pointer to the dynamic stack"></param>
/// <param name="void* - pointer to the data where the popped element will be stored"></param>
/// <returns>0 on failure, 1 on success</returns>
extern unsigned char MyDynamicStack_Pop(MyDynamicStack* HeadNode, void* StackElement);

/// <summary>
/// This function is used to peek the data from the stack
/// </summary>
/// <param name="MyDynamicStack - pointer to the dynamic stack"></param>
/// <param name="void* - pointer to the data where the peeked element will be stored"></param>
/// <returns>0 on failure, 1 on success</returns>
extern unsigned char MyDynamicStack_Peek(MyDynamicStack* HeadNode, void* StackElement);

/// <summary>
/// This function traverse the stack
/// </summary>
/// <param name="HeadNode"></param>
extern void MyDynamicStack_Traverse(MyDynamicStack* HeadNode);

#endif //__STACK_DYNAMIC_H__
