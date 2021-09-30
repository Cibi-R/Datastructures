#include <include.h>
#include BINARY_TREE_H
#include STACK_DYNAMIC_H

static void PreorderRecursive(Node* RootNode);
static void InorderRecursive(Node* RootNode);
static void PostorderRecursive(Node* RootNode);

static void PreorderInterative(Node* rootNode);

unsigned char MyDynamicBinaryTree_Create(MyBinaryTree** RootNode, uint16_t size)
{
	unsigned char retVal = 0;

	(*RootNode) = (MyBinaryTree*)malloc(sizeof(MyBinaryTree));

	if (NULL != (*RootNode))
	{
		/*< create queue to store node address, this library uses the level order insertion algorithm to insert a node */
		if (MyDynamicQueue_Create(&((*RootNode)->LevelOrderQueue), sizeof(void*)))
		{
			(*RootNode)->ElementSize = size;

			(*RootNode)->TreeNode = NULL;

			retVal = 1;
		}
	}

	return retVal;
}

unsigned char MyDynamicBinaryTree_Insert(MyBinaryTree* RootNode, void* Element)
{
	unsigned char retVal = 0;

	Node* newNode = NULL;

	if (NULL != RootNode)
	{
		/*< create new node */
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
			Node* tempNode = RootNode->TreeNode;

			/*< tree is empty */
			if (NULL == tempNode)
			{
				RootNode->TreeNode = newNode;
			}
			else
			{
				/*< This below code snippet implements the level order insersion */
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
						MyDynamicQueue_EnQueue(RootNode->LevelOrderQueue, (void*) &tempNode->left);
					}

					if (NULL != tempNode->right)
					{
						MyDynamicQueue_EnQueue(RootNode->LevelOrderQueue, (void*) &tempNode->right);
					}

					MyDynamicQueue_DeQueue(RootNode->LevelOrderQueue, (void*) &tempNode);
				}

				/*< free the level order queue */
				MyDynamicQueue_Free(RootNode->LevelOrderQueue);

				retVal = 1;
			}
		}
	}

	return retVal;

}

void MyDynamicBinaryTree_PreorderRecursive(MyBinaryTree* MyTree)
{
	Node* tempNode = MyTree->TreeNode;

	PreorderRecursive(tempNode);
}

static void PreorderRecursive(Node* RootNode)
{
	if (NULL != RootNode)
	{
		printf("binary tree element : %d\n", *((unsigned int*)RootNode->Element));
		PreorderRecursive(RootNode->left);
		PreorderRecursive(RootNode->right);
	}
	else
	{
		return;
	}
}

void MyDynamicBinaryTree_InorderRecursive(MyBinaryTree* MyTree)
{
	Node* tempNode = MyTree->TreeNode;

	InorderRecursive(tempNode);
}

static void InorderRecursive(Node* RootNode)
{
	if (NULL != RootNode)
	{
		InorderRecursive(RootNode->left);
		printf("binary tree element : %d\n", *((unsigned int*)RootNode->Element));
		InorderRecursive(RootNode->right);
	}
	else
	{
		return;
	}
}

void MyDynamicBinaryTree_PostorderRecursive(MyBinaryTree* MyTree)
{
	Node* tempNode = MyTree->TreeNode;

	PostorderRecursive(tempNode);
}

static void PostorderRecursive(Node* RootNode)
{
	if (NULL != RootNode)
	{
		PostorderRecursive(RootNode->left);
		PostorderRecursive(RootNode->right);
		printf("binary tree element : %d\n", *((unsigned int*)RootNode->Element));
	}
	else
	{
		return;
	}
}

void MyDynamicBinaryTree_BreadFirstTraversal(MyBinaryTree* myTree)
{
	Node* tempNode;

	if (NULL != myTree)
	{
		tempNode = myTree->TreeNode;

		/*< check whether tree is empty */
		if (NULL != tempNode)
		{
			while (1)
			{
				printf("binary tree element : %d\n", *((unsigned int*)tempNode->Element));

				if (NULL != tempNode->left)
				{
					MyDynamicQueue_EnQueue(myTree->LevelOrderQueue, (void*)&tempNode->left);
				}
				if (NULL != tempNode->right)
				{
					MyDynamicQueue_EnQueue(myTree->LevelOrderQueue, (void*)&tempNode->right);
				}
				
				/*< when queue become empty all element would be traversed */
				if (!MyDynamicQueue_DeQueue(myTree->LevelOrderQueue, (void*)&tempNode))
				{
					break;
				}
			}
		}
	}
}

void MyDynamicBinaryTree_PreorderInterative(MyBinaryTree* MyTree)
{
	Node* tempNode;

	if (NULL != MyTree)
	{
		tempNode = MyTree->TreeNode;

		PreorderInterative(tempNode);
	}
	else
	{
		printf("binary tree is not created!\n");
	}
}

static void PreorderInterative(Node* rootNode)
{
	MyDynamicStack* myStack;

	if (MyDynamicStack_Create(&myStack, sizeof(void*)))
	{
		if (NULL != rootNode)
		{
			while ((rootNode != NULL) || (!MyDynamicStack_Is_Empty(myStack)))
			{
				if (NULL != rootNode)
				{
					printf("binary tree element : %d\n", *((unsigned int*)rootNode->Element));

					MyDynamicStack_Push(myStack, (void*)&rootNode);

					rootNode = rootNode->left;
				}
				else
				{
					MyDynamicStack_Pop(myStack, (void*)&rootNode);

					rootNode = rootNode->right;
				}
			}
		}
		else
		{
			printf("binary tree is empty!\n");
		}
	}
	else
	{
		printf("binary tree traversal aborted due to stack creation failed\n");
	}
}
