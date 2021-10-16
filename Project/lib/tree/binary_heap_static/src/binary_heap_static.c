#include <include.h>
#include STATIC_BINARY_HEAP_H


unsigned char MyStaticBinaryHeap_Create(MyStaticBinaryHeap* MyBinaryHeap, void* Buffer, uint16_t ElementSize,
	uint16_t BufferSize, HeapType heapType)
{
	MyBinaryHeap->ElementSize = ElementSize;

	MyBinaryHeap->BufferSize = BufferSize;

	MyBinaryHeap->TreeBuffer = Buffer;

	MyBinaryHeap->Head = -1;

	MyBinaryHeap->HeapType = heapType;
}

unsigned char MyStaticBinaryHeap_Push(MyStaticBinaryHeap* MyBinaryHeap, void* Element)
{
	unsigned char retVal = 0;

	if (NULL != MyBinaryHeap)
	{
		if (NULL != MyBinaryHeap->TreeBuffer)
		{
			if ((MyBinaryHeap->Head + 1) < MyBinaryHeap->BufferSize)
			{
				MyBinaryHeap->Head++;

				uint16_t currIndex;
				uint16_t parentIndex;
				uint8_t performSwap;

				/*< node value has been inserted as a last value */
				memcpy(&(((unsigned char*)MyBinaryHeap->TreeBuffer)[(MyBinaryHeap->Head * MyBinaryHeap->ElementSize)]),
					Element, MyBinaryHeap->ElementSize);

				/*< bring the inserted last value to its appropriate position based on its value */
				currIndex = MyBinaryHeap->Head;

				while (currIndex != 0)
				{
					parentIndex = currIndex / 2;

					/*< right child index will always be even number */
					if (!(currIndex & 0X01U))
					{
						/*< if it is right child subtract by 1 */
						parentIndex--;
					}

					/*< reset swap status */
					performSwap = 0;

					/*< if current index greater than parent then swap */
					if (MyBinaryHeap->HeapType == MAX_HEAP)
					{
#if 1 /*< the below logic should be implemented based on the priority parameter, here the value itself is a priority */
						if ((((unsigned char*)MyBinaryHeap->TreeBuffer)[(currIndex * MyBinaryHeap->ElementSize)]) >
							(((unsigned char*)MyBinaryHeap->TreeBuffer)[(parentIndex * MyBinaryHeap->ElementSize)]))
						{
							performSwap = 1;
						}
#endif
					}
					else if (MyBinaryHeap->HeapType == MIN_HEAP)
					{
#if 1 /*< the below logic should be implemented based on the priority parameter, here the value itself is a priority */
						if ((((unsigned char*)MyBinaryHeap->TreeBuffer)[(currIndex * MyBinaryHeap->ElementSize)]) <
							(((unsigned char*)MyBinaryHeap->TreeBuffer)[(parentIndex * MyBinaryHeap->ElementSize)]))
						{
							performSwap = 1;
						}
#endif
					}
					else
					{
						/*< do nothing */
					}

					if (performSwap)
					{
#if 1  //below the value of two nodes are swapped, logic can be updated with respect to the priority value
						((unsigned char*)MyBinaryHeap->TreeBuffer)[(currIndex * MyBinaryHeap->ElementSize)] =
							((unsigned char*)MyBinaryHeap->TreeBuffer)[(currIndex * MyBinaryHeap->ElementSize)] ^
							((unsigned char*)MyBinaryHeap->TreeBuffer)[(parentIndex * MyBinaryHeap->ElementSize)];

						((unsigned char*)MyBinaryHeap->TreeBuffer)[(parentIndex * MyBinaryHeap->ElementSize)] =
							((unsigned char*)MyBinaryHeap->TreeBuffer)[(currIndex * MyBinaryHeap->ElementSize)] ^
							((unsigned char*)MyBinaryHeap->TreeBuffer)[(parentIndex * MyBinaryHeap->ElementSize)];

						((unsigned char*)MyBinaryHeap->TreeBuffer)[(currIndex * MyBinaryHeap->ElementSize)] =
							((unsigned char*)MyBinaryHeap->TreeBuffer)[(currIndex * MyBinaryHeap->ElementSize)] ^
							((unsigned char*)MyBinaryHeap->TreeBuffer)[(parentIndex * MyBinaryHeap->ElementSize)];
#endif
					}

					/*< move the current index to parent */
					currIndex = parentIndex;
				}

				retVal = 1;
			}
		}
	}

	return retVal;
}

unsigned char MyStaticBinaryHeap_Pop(MyStaticBinaryHeap* MyBinaryHeap, void* Element)
{
	unsigned char retVal = 0;

	if (NULL != MyBinaryHeap)
	{
		if (NULL != MyBinaryHeap->TreeBuffer)
		{
			/*< check whether heap is empty */
			if (-1 != MyBinaryHeap->Head)
			{
				/*< initialize parentIndex to 0 */
				uint16_t parentIndex = 0;
				uint16_t leftIndex = 0, rightIndex = 0;
				uint16_t compareIndex;

				/*< copy the 0th element */
				memcpy(Element, MyBinaryHeap->TreeBuffer, MyBinaryHeap->ElementSize);

				/*< heap contains more than one element */
				if (0 != MyBinaryHeap->Head)
				{
					/*< copy last element to 0th element, least priority element moved to root of the tree */
					memcpy(
						MyBinaryHeap->TreeBuffer,
						&((unsigned char*)(MyBinaryHeap->TreeBuffer))[MyBinaryHeap->Head * MyBinaryHeap->ElementSize],
						MyBinaryHeap->ElementSize
					);

					/*< one element popped out */
					MyBinaryHeap->Head--;

					/*< TODO: least priority element moved to 0th(root) position, again move the least priority element towards the
					the bottom of the tree by swapping with its chile nodes */
					while (1)
					{
						leftIndex = (parentIndex * 2) + 1;
						rightIndex = (parentIndex + 1) * 2;

						/* TODO : get the index of the biggest element between right and left child */

						/*< if the left and right index are greater than head then stop the operation */
						if ((leftIndex > MyBinaryHeap->Head) && (rightIndex > MyBinaryHeap->Head))
						{
							break;
						}

						/*< both index are within the head value so, check which element is bigger to swap with */
						else if ((leftIndex <= MyBinaryHeap->Head) && (rightIndex <= MyBinaryHeap->Head))
						{
#if 1 // the below logic should be udpated based on the priority value
							compareIndex = (*((int*)(&((unsigned char*)MyBinaryHeap->TreeBuffer)[leftIndex * MyBinaryHeap->ElementSize])) >
								*((int*)(&((unsigned char*)MyBinaryHeap->TreeBuffer)[rightIndex * MyBinaryHeap->ElementSize]))) ?
								leftIndex : rightIndex;
#endif
						}

						/*< left or right child index crossed the head index */
						else
						{
							compareIndex = (leftIndex > MyBinaryHeap->Head) ? rightIndex : leftIndex;
						}
#if 1 // the below logic should be updated based on the priority value
						/*< swap with the biggest element */
						if (((unsigned char*)MyBinaryHeap->TreeBuffer)[parentIndex * MyBinaryHeap->ElementSize]
							<
							((unsigned char*)MyBinaryHeap->TreeBuffer)[compareIndex * MyBinaryHeap->ElementSize])
						{
							*((int*)(&((unsigned char*)MyBinaryHeap->TreeBuffer)[parentIndex * MyBinaryHeap->ElementSize])) =
								*((int*)(&((unsigned char*)MyBinaryHeap->TreeBuffer)[compareIndex * MyBinaryHeap->ElementSize])) ^
								*((int*)(&((unsigned char*)MyBinaryHeap->TreeBuffer)[parentIndex * MyBinaryHeap->ElementSize]));

							*((int*)(&((unsigned char*)MyBinaryHeap->TreeBuffer)[compareIndex * MyBinaryHeap->ElementSize])) =
								*((int*)(&((unsigned char*)MyBinaryHeap->TreeBuffer)[compareIndex * MyBinaryHeap->ElementSize])) ^
								*((int*)(&((unsigned char*)MyBinaryHeap->TreeBuffer)[parentIndex * MyBinaryHeap->ElementSize]));

							*((int*)(&((unsigned char*)MyBinaryHeap->TreeBuffer)[parentIndex * MyBinaryHeap->ElementSize])) =
								*((int*)(&((unsigned char*)MyBinaryHeap->TreeBuffer)[compareIndex * MyBinaryHeap->ElementSize])) ^
								*((int*)(&((unsigned char*)MyBinaryHeap->TreeBuffer)[parentIndex * MyBinaryHeap->ElementSize]));

							parentIndex = compareIndex;
						}
						else
						{
							/*< if the parent is greater than its two child node, then the heap is in idle state */
							break;
						}
#endif
					}
				}
				else
				{
					/*< last element popped */
					MyBinaryHeap->Head = -1;
				}

				retVal = 1;
			}
		}
	}

	return retVal;
}

unsigned char MyStaticBinaryHeap_Heapfy(MyStaticBinaryHeap* MyBinaryHeap)
{
	/**
	 * 1. traverse from the last to head element
	 * 2. a. if an element is greater/less than the right/left chile swap
	 *    b. continue the swapping process till the index reaches head value.
	 **/
}

void MyStaticBinaryHeap_Traverse(MyStaticBinaryHeap* MyBinaryHeap)
{
	if (NULL != MyBinaryHeap)
	{
		if (NULL != MyBinaryHeap->TreeBuffer)
		{
			uint16_t index;

			for (index = 0; index <= MyBinaryHeap->Head; index++)
			{
				printf("element : %d\n",
					*((int*)(&((unsigned char*)(MyBinaryHeap->TreeBuffer))[index * MyBinaryHeap->ElementSize])));
				/*
				 * 1. First convert the TreeBuffer to unsigned char pointer
				 * 2. move to the base pointer position in the array using Heap and ElementSize value
				 * 3. convert address of that positoin to integer pointer
				 * 4. dereference the pointer :)
				 */
			}
		}
	}
}