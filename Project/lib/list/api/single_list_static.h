#ifndef _STATIC_SINGLE_LIST_H_
#define _SINGLE_LIST_STATIC_H_

/**********************************************************************************************************************
 *									          Macro Definitions
 **********************************************************************************************************************/

#define SINGLE_LIST_STATIC_ELEMENT_TYPE unsigned char
#define SINGLE_LIST_STATIC_MAX_SIZE     5


 /**********************************************************************************************************************
  *									          Function Declarations
  **********************************************************************************************************************/


extern unsigned char PushElement(SINGLE_LIST_STATIC_ELEMENT_TYPE Element);

extern SINGLE_LIST_STATIC_ELEMENT_TYPE PopElement(void);

extern unsigned char InsertElement(SINGLE_LIST_STATIC_ELEMENT_TYPE Element, unsigned char Position);

extern SINGLE_LIST_STATIC_ELEMENT_TYPE RemoveElement(unsigned char Position);

extern void Traverse_Single_Static_List(void);

#endif //_SINGLE_LIST_STATIC_H_
