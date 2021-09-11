#ifndef __STACK_H__
#define __STACK_H__

/*********************************************************************************************************************
 *							                       Macro definitions
 ********************************************************************************************************************/

#define STACK_STATIC_ELEMENT_TYPE     unsigned int
#define STACK_STATIC_BUFFER_SIZE      100

/*********************************************************************************************************************
 *							                          typedefs
 ********************************************************************************************************************/

typedef struct MyStackStatic_Tag
{
	int16_t top;
	STACK_STATIC_ELEMENT_TYPE Buffer[STACK_STATIC_BUFFER_SIZE];
}MyStackStatic;

/*********************************************************************************************************************
 *							                     Functions Declarations
 ********************************************************************************************************************/

/// <summary>
/// this function is used to initialize the static stack
/// </summary>
/// <param name="MyStackStatic - pointer to the static stack to be initialized"></param>
/// <returns> void </returns>
extern void MyStaticStack_Init(MyStackStatic* MyStack);

/// <summary>
/// this function pushes an element to the stack
/// </summary>
/// <param name="MyStackStatic - pointer to the static stack"></param>
/// <param name="Element - element to be pushed into the stack"></param>
/// <returns>0 on failure, 1 on success</returns>
extern uint8_t MyStaticStack_Push(MyStackStatic* MyStack, STACK_STATIC_ELEMENT_TYPE Element);

/// <summary>
/// this funciton pops an element from the stack
/// </summary>
/// <param name="MyStackStatic - pointer to the static stack"></param>
/// <param name="Element - base address to the data where the popped element will be stored"></param>
/// <returns>0 on failure, 1 on success</returns>
extern uint8_t MyStaticStack_Pop(MyStackStatic* MyStack, STACK_STATIC_ELEMENT_TYPE* Element);

/// <summary>
/// this funciton peeks(top element) an element from the stack, it will not remove the top element
/// </summary>
/// <param name="MyStackStatic - pointer to the static stack"></param>
/// <param name="Element - base address to the data where the peek element will be stored"></param>
/// <returns>0 on failure, 1 on success</returns>
extern uint8_t MyStaticStack_Peek(MyStackStatic* MyStack, STACK_STATIC_ELEMENT_TYPE* Element);

/// <summary>
/// this function traverses the stack
/// </summary>
/// <param name="MyStackStatic - pointer to the static stack"></param>
/// <returns>void</returns>
extern void MyStaticStack_Traverse(MyStackStatic* MyStack);

#endif //__STACK_H__