#ifndef __BINARY_HEAP_STATIC_H__
#define __BINARY_HEAP_STATIC_H__

/*******************************************************************************************************************
 *                                                    typedef                                                      * 
 *******************************************************************************************************************/
typedef enum HeapType_Tag
{
	MIN_HEAP,
	MAX_HEAP,
	INVALID,
}HeapType;

typedef struct MyStaticBinaryHeap_Tag
{
	void* TreeBuffer;
	uint16_t ElementSize;
	uint16_t BufferSize;
	int16_t Head;
	uint8_t HeapType;
}MyStaticBinaryHeap;

/*******************************************************************************************************************
 *                                              function declaration                                               *
 *******************************************************************************************************************/

/// <summary>
/// This function initializes the static binary heap
/// </summary>
/// <param name="MyBinaryHeap - base address of the heap structure"></param>
/// <param name="Buffer - binary heap buffer"></param>
/// <param name="ElementSize - heap elment size"></param>
/// <param name="BufferSize - heap buffer size"></param>
/// <param name="heapType - min or max heap"></param>
/// <returns>1-success, 0-failure</returns>
unsigned char MyStaticBinaryHeap_Create(MyStaticBinaryHeap* MyBinaryHeap, void * Buffer, 
	uint16_t ElementSize, uint16_t BufferSize, HeapType heapType);

/// <summary>
/// This function pushes the element to the heap
/// </summary>
/// <param name="MyBinaryHeap - base address of the heap structure"></param>
/// <param name="Element - pointer to the element to be pushed"></param>
/// <returns>1-success, 0-failure</returns>
unsigned char MyStaticBinaryHeap_Push(MyStaticBinaryHeap* MyBinaryHeap, void* Element);

/// <summary>
/// This function removes the elment from the heap
/// </summary>
/// <param name="MyBinaryHeap - base address of the heap structure"></param>
/// <param name="Element -  pointer to the element to be pushed"></param>
/// <returns>1-success, 0-failure</returns>
unsigned char MyStaticBinaryHeap_Pop(MyStaticBinaryHeap* MyBinaryHeap, void* Element);

/// <summary>
/// This function heapifies the binary tree
/// </summary>
/// <param name="MyBinaryHeap - base address of the heap structure"></param>
/// <returns>1-success, 0-failure</returns>
unsigned char MyStaticBinaryHeap_Heapfy(MyStaticBinaryHeap* MyBinaryHeap);

/// <summary>
/// This function traverses the binary heap
/// </summary>
/// <param name="MyBinaryHeap - base address of the heap structure"></param>
void MyStaticBinaryHeap_Traverse(MyStaticBinaryHeap* MyBinaryHeap);

#endif //__BINARY_HEAP_STATIC_H__
