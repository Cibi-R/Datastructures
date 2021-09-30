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
		printf("5. Level order/breath first traverse\n6. Preorder interative\n");
		printf("7. Insert 10 to 70 to binary tree\n");

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
			case 5:
			{
				MyDynamicBinaryTree_BreadFirstTraversal(myTree);
				break;
			}
			case 6:
			{
				MyDynamicBinaryTree_PreorderInterative(myTree);
				break;
			}
			case 7:
			{
				for (int value = 10; value < 80; value = value + 10)
				{
					MyDynamicBinaryTree_Insert(myTree, &value);
				}
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