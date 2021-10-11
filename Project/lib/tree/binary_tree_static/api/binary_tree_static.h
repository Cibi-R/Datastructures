#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef struct MyStaticBinaryTree_Tag
{
	void* TreeBuffer;
	uint16_t ElementSize;
	uint16_t BufferSize;
	int16_t Head;
}MyStaticBinaryTree;

/// <summary>
/// This function initializes the static binary tree
/// </summary>
/// <param name="MyTree - base address of MyStaticBinaryTree structure"></param>
/// <param name="Buffer - base address of binary array"></param>
/// <param name="ElementSize - size of the binary tree element"></param>
/// <param name="BufferSize - size of the static binary tree"></param>
/// <returns></returns>
unsigned char MyStaticBinaryTree_Create(MyStaticBinaryTree* MyTree, void* Buffer, uint16_t ElementSize, uint8_t BufferSize);

unsigned char MyStaticBinaryTree_Push(MyStaticBinaryTree* MyTree, void* Element);

void MyStaticBinaryTree_BreadFirstTraversal(MyStaticBinaryTree* MyTree);


#endif //__BINARY_TREE_H__