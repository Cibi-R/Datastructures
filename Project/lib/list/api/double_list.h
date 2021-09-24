#ifndef __DOUBLE_LIST_H__
#define __DOUBLE_LIST_H__

/*********************************************************************************************************************
 *							                           Typedefs
 ********************************************************************************************************************/

typedef struct _MyDoubleList
{
	struct _MyDoubleList* Previous;
	void* Element;
	struct _MyDoubleList* Next;
}MyDoubleList;


/*********************************************************************************************************************
 *							                       Function declarations
 ********************************************************************************************************************/

/// <summary>
/// This function is used to create doubly linked list
/// </summary>
/// <param name="RootNode"></param>
/// <param name="ElementSize"></param>
/// <returns></returns>
extern unsigned char MyDoubleList_Create(MyDoubleList** RootNode, uint16_t ElementSize);

/// <summary>
/// This function is used to push element to the doubly linked list
/// </summary>
/// <param name="RootNode - Base address of doubly linked list"></param>
/// <param name="Element - Address of data to be pushed"></param>
/// <returns> 1-success, 0-failure </returns>
extern unsigned char MyDoubleList_PushElement(MyDoubleList* RootNode, void* Element);

/// <summary>
/// This function is used to pop element from the doubly linked list
/// </summary>
/// <param name="RootNode - Base address of doubly linked list"></param>
/// <param name="Element - Address of data where popped element will be stored"></param>
/// <returns> 1-success, 0-failure </returns>
extern unsigned char MyDoubleList_PopElement(MyDoubleList* RootNode, void* Element);

/// <summary>
/// This function is used to insert an element to the doubly linked list
/// </summary>
/// <param name="RootNode - pointer to the head node"></param>
/// <param name="Element - Address of the data to be inserted"></param>
/// <param name="Position - Position of the list where the element will be pushed"></param>
/// <returns>0 on failure, 1 on success</returns>
extern unsigned char MyDoubleList_InsertElement(MyDoubleList* RootNode, void* Element, uint16_t Position);

/// <summary>
/// This function is used to remove an element from the doubly linked list
/// </summary>
/// <param name="RootNode - pointer to the head node"></param>
/// <param name="Element - Address of the data where removed element will be stored"></param>
/// <param name="Position - Position of the element to be removed"></param>
/// <returns>0 on failure, 1 on success</returns>
extern unsigned char MyDoubleList_RemoveElement(MyDoubleList* RootNode, void* Element, uint16_t Position);

/// <summary>
/// This function is used to get an element from the list without removing it
/// </summary>
/// <param name="RootNode - pointer to the head node"></param>
/// <param name="Element - Address of the data where the list element will be stored"></param>
/// <param name="Position - Position of the element to be retrieved"></param>
/// <returns>0 on failure, 1 on success</returns>
extern unsigned char MyDoubleList_GetElement(MyDoubleList* RootNode, void* Element, uint16_t Position);


/// <summary>
/// This function traverses the list
/// </summary>
extern void MyDoubleList_Traverse(MyDoubleList* RootNode);

#endif //__DOUBLE_LIST_H__
