#include <include.h>
#include BINARY_TREE_H


MyBTree* GetMyBTree(void)
{
	MyBTree* NewTree = (MyBTree*)malloc(sizeof(MyBTree));

	if (NewTree)
	{
		NewTree->Element = 0;
		NewTree->Left = NULL;
		NewTree->Right = NULL;
	}

	return NewTree;
}

unsigned char MyBTree_InsertElement(MyBTree* Tree, BINARY_TREE_ELEMENT_TYPE Element)
{
	unsigned char RetVal = 1;

	if (Tree == NULL)
	{
		return 0;
	}

	MyBTree* NewNode = (MyBTree*)malloc(sizeof(MyBTree));

	if (NewNode == NULL)
	{
		return 0;
	}

	else if (Tree->Right == NULL)
	{
		Tree->Right = NewNode;
	}

	else
	{
		MyBTree* Temp = Tree->Right;

		while (Temp != NULL)
		{
			if (Element <= Temp->Element)
			{
				if (Temp->Left == NULL)
				{
					Temp->Left = NewNode;
					break;
				}
				else
				{
					Temp = Temp->Left;
				}
			}

			else
			{
				if (Temp->Right == NULL)
				{
					Temp->Right = NewNode;
					break;
				}
				else
				{
					Temp = Temp->Right;
				}
			}
		}
	}

	NewNode->Element = Element;
	NewNode->Left = NULL;
	NewNode->Right = NULL;

	return RetVal;
}

unsigned char MyBTree_FindElement(MyBTree* Tree, BINARY_TREE_ELEMENT_TYPE Element)
{
	unsigned char IsElementFound = 0;

	if (Tree != NULL)
	{
		Tree = Tree->Right;

		while (Tree != NULL)
		{
			if (Tree->Element == Element)
			{
				IsElementFound = 1;
				break;
			}

			else if (Element < Tree->Element)
			{
				Tree = Tree->Left;
			}

			else
			{
				Tree = Tree->Right;
			}
		}
	}

	return IsElementFound;
}