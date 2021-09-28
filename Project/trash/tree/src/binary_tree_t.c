#include <include.h>
#include BINARY_TREE_H

void UnitTest1_MyBinaryTree(void)
{
	unsigned int option;

	MyBinaryTree *myTree;

	MyDynamicTree_Create(&myTree, sizeof(unsigned int));

	printf(" ****************************************************************************************************\n \
		                        My BinaryTree Unit Test 1                                           \n \
****************************************************************************************************\n");

	while (1)
	{
		printf("### Enter the option ###\n1. Insert element\n2. InOrder Traversal - Recursive\n");
		scanf("%d", &option);

		switch (option)
		{
			case 1:
			{
				printf("Enter the element : \n");
				scanf("%d", &option);

				if (MyDynamicTree_Insert(myTree, &option))
				{
					printf("element inserted succesfully\n");
				}
				else
				{
					printf("element insertion failed\n");
				}
				break;
			}
			case 2:
			{
				MyDynamicBinaryTree_Traverse(myTree);
			}
		}
	}
}