#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

/*********************************************************************************************************************
 *							                           Header files
 ********************************************************************************************************************/
#include <include.h>
#include QUEUE_DYNAMIC_H

/*********************************************************************************************************************
 *							                           Typedefs
 ********************************************************************************************************************/

typedef struct Node_Tag
{
	struct Node_Tag* left;
	struct Node_Tag* right;
	void* Element;
}Node;

typedef struct MyBinaryTree_Tag
{
	Node* TreeNode;
	uint16_t ElementSize;
	MyDynamicQueue* LevelOrderQueue;
}MyBinaryTree;

/// <summary>
/// This function is used to create a dynamic binary tree.
/// </summary>
/// <param name="RootNode - base address to the binary tree"></param>
/// <param name="size - size of the binary tree element"></param>
/// <returns>1-success, 0-failure</returns>
extern unsigned char MyDynamicTree_Create(MyBinaryTree** RootNode, uint16_t size);

/// <summary>
/// This function is used to insert an element to the list
/// </summary>
/// <param name="RootNode - base address to the binary tree"></param>
/// <param name="Element - address of the element to be inserted"></param>
/// <returns>1-success, 0-failure</returns>
extern unsigned char MyDynamicTree_Insert(MyBinaryTree* RootNode, void* Element);

/// <summary>
/// This function traverses the binary tree
/// </summary>
/// <param name="MyTree - Base address of the binary tree"></param>
void MyDynamicBinaryTree_Traverse(MyBinaryTree* MyTree);

#endif //__BINARY_TREE_H__