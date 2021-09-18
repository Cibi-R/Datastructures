#ifndef _STATIC_SINGLE_LIST_H_
#define _SINGLE_LIST_STATIC_H_

/**********************************************************************************************************************
 *									          Macro Definitions
 **********************************************************************************************************************/

#define SINGLE_LIST_STATIC_ELEMENT_TYPE unsigned char
#define SINGLE_LIST_STATIC_MAX_SIZE     5

/*********************************************************************************************************************
 *							                          typedefs
 ********************************************************************************************************************/

typedef struct MyListStatic_Tag
{
	int16_t top;
	SINGLE_LIST_STATIC_ELEMENT_TYPE Buffer[SINGLE_LIST_STATIC_MAX_SIZE];
}MyListStatic;


 /**********************************************************************************************************************
  *									          Function Declarations
  **********************************************************************************************************************/

/// <summary>
/// This function is used to initialzie the static list
/// </summary>
/// <param name="MyList - pointer to the static list"></param>
extern void MyStaticLlist_Init(MyListStatic* MyList);

/// <summary>
/// This function is used to push an element to the list
/// </summary>
/// <param name="MyList - Pointer to the static list"></param>
/// <param name="Element - Element to be pushed into the list"></param>
/// <returns> 1-success, 0-failure</returns>
extern unsigned char MyStaticList_PushElement(MyListStatic* MyList, SINGLE_LIST_STATIC_ELEMENT_TYPE Element);

/// <summary>
/// This function is used to pop an element from the list
/// </summary>
/// <param name="MyList - Pointer to the static list"></param>
/// <param name="Element - Pointer to the data wherer popped element will be stored"></param>
/// <returns>1-success, 0-failure</returns>
extern unsigned char MyStaticList_PopElement(MyListStatic* MyList, SINGLE_LIST_STATIC_ELEMENT_TYPE* Element);

/// <summary>
/// This function is used to insert an element to the list
/// </summary>
/// <param name="MyList - Pointer to the static list"></param>
/// <param name="Element - Element to be inserted"></param>
/// <param name="Position - Position of the element to be inserted"></param>
/// <returns>1-success, 0-failure</returns>
extern unsigned char MyStaticList_InsertElement(MyListStatic* MyList, SINGLE_LIST_STATIC_ELEMENT_TYPE Element, int16_t Position);

/// <summary>
/// This function is used to remove element from the list
/// </summary>
/// <param name="MyList - Pointer to the static list"></param>
/// <param name="Element - Base address of data where removed element will be stored"></param>
/// <param name="Position - Position of the element to be retrieved"></param>
/// <returns>0-success, 1-failure</returns>
extern unsigned char MyStaticList_RemoveElement(MyListStatic* MyList, SINGLE_LIST_STATIC_ELEMENT_TYPE* Element, int16_t Position);

/// <summary>
/// This function is used to traverse the list
/// </summary>
/// <param name="MyList - Pointer to the static list"></param>
extern void MyStaticList_Traverse(MyListStatic* MyList);

#endif //_SINGLE_LIST_STATIC_H_
