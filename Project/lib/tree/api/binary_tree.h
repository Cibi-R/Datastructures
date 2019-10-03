#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#define BINARY_TREE_ELEMENT_TYPE unsigned char

typedef struct _MyBTree
{
	struct MyBTree* Left;
	BINARY_TREE_ELEMENT_TYPE Element;
	struct MyBTree* Right;
}MyBTree;

extern MyBTree* GetMyBTree(void);

extern unsigned char MyBTree_InsertElement(MyBTree* Tree, BINARY_TREE_ELEMENT_TYPE Element);

extern unsigned char MyBTree_FindElement(MyBTree* Tree, BINARY_TREE_ELEMENT_TYPE Element);

#endif //_BINARY_TREE_H_
