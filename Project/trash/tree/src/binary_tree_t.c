#include <include.h>
#include BINARY_TREE_H
#include QUEUE_DYNAMIC_H


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
		printf("7. Inorder interative\n8. Postorder interative\n");
		printf("9. Insert binary tree with range of number\n");

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
				MyDynamicBinaryTree_InorderInterative(myTree);
				break;
			}
			case 8:
			{
				MyDynamicBinaryTree_PostorderInterative(myTree);
				break;
			}
			case 9:
			{
				
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

void BinaryTree_InsertWithRange(MyBinaryTree *myTree)
{
	unsigned int range1;
	unsigned int range2;

	printf("Enter the starting value : ");
	scanf("%d", &range1);
	printf("Enter the end value : ");
	scanf("%d", &range2);

	for (int value = range1; value < range2; value++)
	{
		MyDynamicBinaryTree_Insert(myTree, &value);
	}
}