#include <include.h>
#include STATIC_BINARY_TREE_H

unsigned char MyStaticBinaryTree_Create(MyStaticBinaryTree* MyTree, void* Buffer,  uint16_t ElementSize, uint8_t BufferSize)
{
	MyTree->ElementSize = ElementSize;

	MyTree->BufferSize = BufferSize;

	MyTree->TreeBuffer = Buffer;

	MyTree->Head = -1;
}

unsigned char MyStaticBinaryTree_Push(MyStaticBinaryTree* MyTree, void* Element)
{
	unsigned char retVal = 0;

	if (MyTree != NULL)
	{
		/*< if the values are inserted continuously it will simulate the level order insertion */
		MyTree->Head++;

		memcpy(&(((unsigned char*)MyTree->TreeBuffer)[(MyTree->Head * MyTree->ElementSize)]), 
			Element, MyTree->ElementSize);

		retVal = 1;
	}

	return retVal;
}

void MyStaticBinaryTree_BreadFirstTraversal(MyStaticBinaryTree* MyTree)
{
	int16_t i;

	if (NULL != MyTree)
	{
		if (NULL != MyTree->TreeBuffer)
		{
			if (0 <= MyTree->Head)
			{
				for (int16_t i = 0; i <= MyTree->Head; i++)
				{
					printf("Element : %d\n", ((unsigned int*)MyTree->TreeBuffer)[i]);
				}
			}
			else
			{
				printf("binary tree is empty\n");
			}
		}
		else
		{
			printf("invalid binary tree buffer\n");
		}
	}
	else
	{
		printf("invlalid / null pointer to the binary tree\n");
	}
}

void MyStaticBinaryTree_PreorderInterative(MyStaticBinaryTree* MyTree)
{
	if (NULL != MyTree)
	{
		if (NULL != MyTree->TreeBuffer)
		{
			if (-1 == MyTree->Head)
			{
				printf("binary tree is empty\n");
			}
			else
			{
				uint16_t index;

				for (uint16_t i = 0; i <= MyTree->Head; i++)
				{
					index = i;

					while (index <= MyTree->Head)
					{
						printf("Element : %d\n", ((unsigned int*)MyTree->TreeBuffer)[i]);

						/*< left sub tree */
						index = (2 * i) + 1;
					}
				}
			}
		}
	}
}
