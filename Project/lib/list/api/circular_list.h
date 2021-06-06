#ifndef __CIRCULAR_LIST_H__
#define __CIRCULAR_LIST_H__

#define CIRCULAR_SINGLY_LIST_ELEMENT_TYPE unsigned char

typedef struct _MyCircularSinglyList
{
	CIRCULAR_SINGLY_LIST_ELEMENT_TYPE Element;
	struct _MyCircularSinglyList*Next;
}MyCircularSinglyList;

extern MyCircularSinglyList* GetCircularSinglyList(void);

extern unsigned char CircularList_PushElement(MyCircularSinglyList* List, CIRCULAR_SINGLY_LIST_ELEMENT_TYPE Element);

extern unsigned char CircularList_PopElement(MyCircularSinglyList* List, CIRCULAR_SINGLY_LIST_ELEMENT_TYPE* Element);

extern unsigned char CircularList_InsertElement(MyCircularSinglyList* List, CIRCULAR_SINGLY_LIST_ELEMENT_TYPE Element, uint32_t Position);

extern unsigned char CircularList_RemoveElement(MyCircularSinglyList* List, CIRCULAR_SINGLY_LIST_ELEMENT_TYPE* Element, uint32_t Position);

extern void CircularList_Traverse(MyCircularSinglyList* List);

#endif //__CIRCULAR_LIST_H__

