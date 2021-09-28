#include <include.h>
#include BINARY_TREE_H

static void MyDynamicBinaryTree_InOrder_Recursive(Node* RootNode);

unsigned char MyDynamicTree_Create(MyBinaryTree** RootNode, uint16_t size)
{
	unsigned char retVal = 0;

	(*RootNode) = (MyBinaryTree*)malloc(sizeof(MyBinaryTree));

	if (NULL != (*RootNode))
	{
		/*< create queue for binary tree, this library uses the level order insertion algorithm to insert a node */
		if (MyDynamicQueue_Create(&((*RootNode)->LevelOrderQueue), sizeof(Node)))
		{
			(*RootNode)->ElementSize = size;

			(*RootNode)->TreeNode = NULL;

			retVal = 1;
		}
	}

	return retVal;
}

unsigned char MyDynamicTree_Insert(MyBinaryTree* RootNode, void* Element)
{
	unsigned char retVal = 0;

	Node* newNode = NULL;

	if (NULL != RootNode)
	{
		newNode = (void*)malloc(sizeof(Node));

		if (NULL != newNode)
		{
			newNode->Element = (void*)malloc(RootNode->ElementSize);

			if (NULL != newNode->Element)
			{
				newNode->left = NULL;
				newNode->right = NULL;
				memcpy(newNode->Element, Element, RootNode->ElementSize);

				retVal = 1;
			}
			else
			{
				free(newNode);
			}
		}
		
		/*< new node created successfully */
		if (retVal)
		{
			if (NULL == RootNode->TreeNode)
			{
				RootNode->TreeNode = newNode;
			}
			else
			{
				Node* tempNode = RootNode->TreeNode;

				while (1)
				{
					if (NULL == tempNode->left)
					{
						tempNode->left = newNode;

						break;
					}
					else if (NULL == tempNode->right)
					{
						tempNode->right = newNode;

						break;
					}
					else { /*< Do nothing */ }

					if (NULL != tempNode->left)
					{
						MyDynamicQueue_EnQueue(RootNode->LevelOrderQueue, tempNode->left);
					}

					if (NULL != tempNode->right)
					{
						MyDynamicQueue_EnQueue(RootNode->LevelOrderQueue, tempNode->right);
					}

					MyDynamicQueue_DeQueue(RootNode->LevelOrderQueue, tempNode);
				}

				/*< free the level order queue */
				MyDynamicQueue_Free(RootNode->LevelOrderQueue);

				retVal = 1;
			}
		}
	}

	return retVal;
}

void MyDynamicBinaryTree_Traverse(MyBinaryTree* MyTree)
{
	Node* tempNode = MyTree->TreeNode;

	MyDynamicBinaryTree_InOrder_Recursive(tempNode);
}

static void MyDynamicBinaryTree_InOrder_Recursive(Node* RootNode)
{
	if (NULL != RootNode)
	{
		printf("binary tree element : %d\n", *((unsigned int*)RootNode->Element));
		MyDynamicBinaryTree_InOrder_Recursive(RootNode->left);
		MyDynamicBinaryTree_InOrder_Recursive(RootNode->right);
	}
}