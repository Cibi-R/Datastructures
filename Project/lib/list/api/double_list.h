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

extern unsigned char DoubleList_PopElement(MyDoubleList* List, DOUBLE_LIST_ELEMENT_TYPE* Element);

extern unsigned char DoubleList_InsertElement(MyDoubleList* List, DOUBLE_LIST_ELEMENT_TYPE Element, uint32_t Position);

unsigned char DoubleList_RemoveElement(MyDoubleList* List, DOUBLE_LIST_ELEMENT_TYPE* Element, unsigned char Position);

extern void DoubleList_TraverseElement(MyDoubleList* List);

#endif //__DOUBLE_LIST_H__
