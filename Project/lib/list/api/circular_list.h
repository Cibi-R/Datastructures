#ifndef __CIRCULAR_LIST_H__
#define __CIRCULAR_LIST_H__

/*********************************************************************************************************************
 *							                           Typedefs
 ********************************************************************************************************************/

typedef struct _MyCircularSinglyList
{
	void* Element;
	struct _MyCircularSinglyList* Next;
}MyCircularSinglyList;

/*********************************************************************************************************************
 *							                       Function declarations
 ********************************************************************************************************************/

/// <summary>
/// This function is used to create circular list
/// </summary>
/// <param name="HeadNode - pointer to the headnode"></param>
/// <param name="Size - Size of the element of circular list"></param>
/// <returns> 1-success 0-failure </returns>
extern unsigned char MyCircularList_Create(MyCircularSinglyList **HeadNode, uint16_t Size);

/// <summary>
/// This function is used to push element to the list
/// </summary>
/// <param name="HeadNode - Base address of the circular list"></param>
/// <param name="Element - Address of the data to be pushed"></param>
/// <returns> 1-success 0-failure </returns>
extern unsigned char MyCircularList_PushElement(MyCircularSinglyList* HeadNode, void* Element);

/// <summary>
/// This function is used to pop element from the list
/// </summary>
/// <param name="HeadNode - Address to the head node"></param>
/// <param name="Element - addredd of the data where the popped element will be stored"></param>
/// <returns> 1-success 0-failure </returns>
extern unsigned char MyCircularList_PopElement(MyCircularSinglyList* HeadNode, void* Element);

/// <summary>
/// This function is used to insert an element to the list
/// </summary>
/// <param name="HeadNode - Base address of the circular list"></param>
/// <param name="Element - Address of the data to be inserted"></param>
/// <param name="Position - Position at where the element will be pushed"></param>
/// <returns> 1-success 0-failure </returns>
extern unsigned char MyCircularList_InsertElement(MyCircularSinglyList* HeadNode, void* Element, uint16_t Position);

/// <summary>
/// This function is used to remove an element from the list
/// </summary>
/// <param name="HeadNode - Base address of the circular list"></param>
/// <param name="Element - Address of the data where the removed element will be stored"></param>
/// <param name="Position - Position of the element to be removed"></param>
/// <returns> 1-success 0-failure </returns>
extern unsigned char MyCircularList_RemoveElement(MyCircularSinglyList* List, void* Element, uint16_t Position);

/// <summary>
/// This function is used to traverse the list
/// </summary>
/// <param name="HeadNode"></param>
/// <returns></returns>
extern unsigned char MyCiruclarList_Traverse(MyCircularSinglyList* HeadNode);

#endif //__CIRCULAR_LIST_H__

