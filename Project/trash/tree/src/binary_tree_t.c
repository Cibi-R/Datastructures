#include <include.h>
#include BINARY_TREE_H

void UnitTest1_MyBinaryTree(void)
{
	unsigned int option;

	MyBinaryTree *myTree;

	MyDynamicBinaryTree_Create(&myTree, sizeof(unsigned int));

	printf(" ****************************************************************************************************\n \
		                        My BinaryTree Unit Test 1                                           \n \
****************************************************************************************************\n");

	while (1)
	{
		printf("### Enter the option ###\n1. Insert element\n2. PreOrder Traversal - Recursive\n");
		printf("3. InOrder Traversal - Recusive\n4. PostOrder Traversal - Recursive\n");

		scanf("%d", &option);

		switch (option)
		{
			case 1:
			{
				printf("Enter the element : \n");
				scanf("%d", &option);

				if (MyDynamicBinaryTree_Insert(myTree, &option))
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
				MyDynamicBinaryTree_PreorderRecursive(myTree);
				break;
			}
			case 3:
			{
				MyDynamicBinaryTree_InorderRecursive(myTree);
				break;
			}
			case 4:
			{
				MyDynamicBinaryTree_PostorderRecursive(myTree);
				break;
			}
			default:
			{
				printf("invalid option\n");
				break;
			}
		}
	}
}