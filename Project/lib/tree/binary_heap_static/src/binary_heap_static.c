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
#if 1 /*< the below logic should implemented based on the priority parameter, here the value itself is a priority */
						if ((((unsigned char*)MyBinaryHeap->TreeBuffer)[(currIndex * MyBinaryHeap->ElementSize)]) >
							(((unsigned char*)MyBinaryHeap->TreeBuffer)[(parentIndex * MyBinaryHeap->ElementSize)]))
						{
							performSwap = 1;
						}
#endif
					}
					else if (MyBinaryHeap->HeapType == MIN_HEAP)
					{
#if 1 /*< the below logic should implemented based on the priority parameter, here the value itself is a priority */
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

}

unsigned char MyStaticBinaryHeap_Heapfy(MyStaticBinaryHeap* MyBinaryHeap)
{

}

void MyStaticBinaryHeap_Traverse(MyStaticBinaryHeap* MyBinaryHeap)
{

}