#include <include.h>
#include BINARY_SEARCH_TREE_H


void Execute_Tree(void)
{
	int Option;

	MyBTree* Bin_Tree = GetMyBTree();

	while (1)
	{
		printf_s("1. Insert Element\n2. In Order Traversal\n3. Pre Order Traversal\n");
		printf_s("4. Post Order Traversal\n5. Find Element\n6. Delete Element\n");

		switch (Option)
		{
			case 1:
			{
				printf_s("Enter the Element : \n");
				scanf_s("%d", &Option);
				if (MyBTree_InsertElement(Bin_Tree, Option))
				{
					printf_s("Element inserted successfully\n");
				}
				else { printf_s("Failed at inserting element\n"); }
				break;
			}

			case 5:
			{
				printf_s("Enter the Element : \n");
				scanf_s("%d", &Option);

				if (MyBTree_FindElement(Bin_Tree, Option))
				{
					printf_s("Element found!\n");
				}
				else { printf_s("Element not found!\n"); }
				break;
			}
		}
	}
}