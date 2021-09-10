#include <include.h>
#include STACKt_H
#include STACK_DYNAMICt_H
#include QUEUE_DYNAMICt_H
#include SINGLE_LIST_STATICt_H
#include SINGLE_LISTt_H
#include CIRCULAR_LISTt_H
#include BINARY_SEARCH_TREE_H
#include DOUBLE_LISTt_H

extern void Execute_Tree(void);

int main()
{
#if 0
	UnitTest1_MyStaticQueue();
#endif
#if 1
	UnitTest1_MyDynamicQueue();
#endif
	//Execute_Tree();

	//Execute_Double_List();

#if 0
	Execute_Circular_Singly_List();
#endif

	while (1);
}

