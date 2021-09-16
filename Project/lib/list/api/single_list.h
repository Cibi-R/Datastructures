#ifndef __SINGLE_LIST_H__
#define __SINGLE_LIST_H__


 /*********************************************************************************************************************
  *							                           Typedefs
  ********************************************************************************************************************/

typedef struct _MySingleList
{
	void* Element;
	struct _MySingleList *Next;
}MySingleList;


/*********************************************************************************************************************
 *							                       Function declarations
 ********************************************************************************************************************/

 /// <summary>
 /// this function is used to create the single list (dynamically allocates memory to the root node)
 /// </summary>
 /// <param name="HeadNode - pointer to the head node pointer"></param>
 /// <returns>0 on failure, 1 on success</returns>
extern unsigned char MySingleList_Create(MySingleList **RootNode, uint16_t ElementSize);

 /// <summary>
 /// This function is used to push an element to a list.
 /// </summary>
 /// <param name="RootNode - pointer to the head node"></param>
 /// <param name="Element - Base address of the data to be pushed"></param>
 /// <returns>0 on failure, 1 on success</returns>
extern unsigned char MySingleList_PushElement(MySingleList* RootNode, void* Element);


 /// <summary>
 /// This function is used to pop the last element from the list.
 /// </summary>
 /// <param name="RootNode - pointer to the head node"></param>
 /// <param name="Element - Address of data where the popped element will be stored"></param>
 /// <returns>0 on failure, 1 on success</returns>
extern unsigned char MySingleList_PopElement(MySingleList* RootNode, void* Element);

/// <summary>
/// This function is used to insert an element to the list
/// </summary>
/// <param name="RootNode - pointer to the head node"></param>
/// <param name="Element - Address of the data to be inserted"></param>
/// <param name="Position - Position of the list where the element will be pushed"></param>
/// <returns>0 on failure, 1 on success</returns>
extern unsigned char MySingleList_InsertElement(MySingleList* RootNode, void* Element, uint16_t Position);

/// <summary>
/// This function is used to remove an element from the list
/// </summary>
/// <param name="RootNode - pointer to the head node"></param>
/// <param name="Element - Address of the data where removed element will be stored"></param>
/// <param name="Position - Position of the element to be removed"></param>
/// <returns>0 on failure, 1 on success</returns>
extern unsigned char MySingleList_RemoveElement(MySingleList* RootNode, void* Element, uint16_t Position);

/// <summary>
/// This function is used to get an element from the list without removing it
/// </summary>
/// <param name="RootNode - pointer to the head node"></param>
/// <param name="Element - Address of the data where the list element will be stored"></param>
/// <param name="Position - Position of the element to be retrieved"></param>
/// <returns>0 on failure, 1 on success</returns>
extern unsigned char MySingleList_GetElement(MySingleList* RootNode, void* Element, uint16_t Position);


/// <summary>
/// This function traverses the list
/// </summary>
extern unsigned char MySingleList_Traverse(MySingleList* RootNode);

#endif //__SINGLE_LIST_H__
