#ifndef __SINGLE_LIST_H__
#define __SINGLE_LIST_H__

#define ELEMENT_TYPE_SINGLE_LIST unsigned int

typedef struct _MySingleList
{
	ELEMENT_TYPE_SINGLE_LIST Element;
	struct _MySingleList *Next;
}MySingleList;

#endif //__SINGLE_LIST_H__
