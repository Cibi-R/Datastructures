#include <include.h>
#include STACK_STATICt_H
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
	/*< static queue unit test */
#if 0
	UnitTest1_MyStaticQueue();
#endif

	/*< dynamic queue unit test */
#if 0
	UnitTest1_MyDynamicQueue();
#endif

	/*< static stack unit test */
#if 0
	UnitTest1_MyStaticStack();
#endif 

	/*< dynamic queue unit test */
#if 0
	UnitTest1_MyDynamicStack();
#endif

	/*< singly circular list unit test */
#if 0
	UnitTest1_MySingleList();
#endif

#if 1
	UnitTest1_MyCircularList();
#endif

	while (1);
}

