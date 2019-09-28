#ifndef __DOUBLE_LIST_H__
#define __DOUBLE_LIST_H__

#define DOUBLE_LIST_ELEMENT_TYPE unsigned char

typedef struct _MyDoubleList
{
	struct _MyDoubleList* Previous;
	DOUBLE_LIST_ELEMENT_TYPE Element;
	struct _MyDoubleList* Next;
}MyDoubleList;

extern MyDoubleList* GetMyDoubleList(void);

extern unsigned char DoubleList_PushElement(MyDoubleList* List, DOUBLE_LIST_ELEMENT_TYPE Element);

extern void DoubleList_TraverseElement(MyDoubleList* List);

#endif //__DOUBLE_LIST_H__
