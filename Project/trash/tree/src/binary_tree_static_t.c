#include <include.h>
#include STATIC_BINARY_TREE_H

void UnitTest1_MyStaticBinaryTree(void)
{
	int option; 

	unsigned int Buffer[100];

	MyStaticBinaryTree myTree;

	MyStaticBinaryTree_Create(&myTree, &Buffer[0], sizeof(unsigned int), 100u);

	printf(" ****************************************************************************************************\n \
		                        My StaticBinaryTree Unit Test 1                                           \n \
****************************************************************************************************\n");

	while (1)
	{
		printf_s("### Enter the option ###\n1. Insert Element\n2. Insert value automatically\n");
		printf_s("3. traverse binary tree\n");

		scanf("%d", &option);

		switch (option)
		{
			case 1:
			{
				break;
			}
			case 2:
			{
				int startVal, endVal;
				printf("start value : \n");
				scanf("%d", &startVal);
				printf("end value : \n");
				scanf("%d", &endVal);
				for (; startVal <= endVal; startVal++)
				{
					if (!MyStaticBinaryTree_Push(&myTree, &startVal))
					{
						printf("value insertion failed\n");
						break;
					}
				}
				if ((startVal-1) == endVal)
				{
					printf("value inserted successfully\n");
				}
				break;
			}
			case 3:
			{
				MyStaticBinaryTree_BreadFirstTraversal(&myTree);
				break;
			}
			default:
			{
				break;
			}
		}
	}
}