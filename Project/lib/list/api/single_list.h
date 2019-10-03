#ifndef __SINGLE_LIST_H__
#define __SINGLE_LIST_H__


/*********************************************************************************************************************
 *							                       Preprocessor Constants
 ********************************************************************************************************************/

#define ELEMENT_TYPE_SINGLE_LIST unsigned int


 /*********************************************************************************************************************
  *							                         Typedefinitions
  ********************************************************************************************************************/

typedef struct _MySingleList
{
	ELEMENT_TYPE_SINGLE_LIST Element;
	struct _MySingleList *Next;
}MySingleList;


/*********************************************************************************************************************
 *							                       Function declarations
 ********************************************************************************************************************/
/*
 *  @brief : This function is used to create the Head Pointer to a list."Next" member is used hold the address 
             of the first node in the list.
 *  @param : void.
 *  @return: MySingleList. dynamically created Pointer to a head node.
 */
extern MySingleList* GetSingleList(void);


/*
 *  @brief : This function is used to push an element to a list.
 *  @param : Pointer to a HeadNode.
 *  @return: unsigned char. Element to be pushed.
 */
extern unsigned char SingleList_PushElement(MySingleList* MyList, ELEMENT_TYPE_SINGLE_LIST Element);


/*
 *  @brief : This function is used to get an element from a specified location in the list.
 *  @param : Pointer to a HeadNode and Position.
 *  @return: Element from the specified location on success. 0 on failure.
 */
extern ELEMENT_TYPE_SINGLE_LIST SingleList_GetElement(MySingleList* MyList, unsigned char Position);


/*
 *  @brief : This function is used to insert an element to a list at a specified location. This function won't delete the Node
 *  @param : Pointer to a HeadNode, Element, Position
 *  @return: unsigned char.
 */
extern unsigned char SingleList_InsertElement(MySingleList* MyList, ELEMENT_TYPE_SINGLE_LIST Element, int Position);


/*
 *  @brief : This function is used to remove an element at a specified location.
 *  @param : Pointer to a HeadNode and position
 *  @return: Element on success, 0 on failure.
 */
ELEMENT_TYPE_SINGLE_LIST SingleList_RemoveElement(MySingleList* MyList,int Position);


/*
 *  @brief : This function is used to Pop an element from a list.
 *  @param : Pointer to a HeadNode.
 *  @return: Element on success, 0 on failure.
 */
ELEMENT_TYPE_SINGLE_LIST SingleList_PopElement(MySingleList* MyList);


/*
 *  @brief : This function is used to traverse the list.
 *  @param : Pointer to a HeadNode.
 *  @return: void.
 */
void SingleList_Travese(MySingleList* MyList);

#endif //__SINGLE_LIST_H__
