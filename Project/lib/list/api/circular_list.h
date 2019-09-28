#ifndef __CIRCULAR_LIST_H__
#define __CIRCULAR_LIST_H__

#define CIRCULAR_LIST_ELEMENT_TYPE unsigned char

typedef struct _MyCircularList
{
	CIRCULAR_LIST_ELEMENT_TYPE Element;
	struct _MyCircularList *Next;
}MyCircularList;

extern MyCircularList* GetCircularList(void);

extern unsigned char CircularList_PushElement(MyCircularList* List, CIRCULAR_LIST_ELEMENT_TYPE Element);

extern void CircularList_Traverse(MyCircularList* List);

#endif //__CIRCULAR_LIST_H__

