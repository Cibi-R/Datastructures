#include <include.h>
#include STATIC_BINARY_HEAP_H

void UnitTest1_MyStaticBinaryHeap(void)
{
	int option;

	int heapBuffer[100];

	MyStaticBinaryHeap myHeap;

	MyStaticBinaryHeap_Create(&myHeap, heapBuffer, sizeof(int), 100, MAX_HEAP);

	printf(" ****************************************************************************************************\n \
		                        My StaticBinaryHeap Unit Test 1                                           \n \
****************************************************************************************************\n");

	while (1)
	{
		printf_s("1. Insert Element\n2. Traverse element\n");
		scanf("%d", &option);

		switch (option)
		{
			case 1:
			{
				printf_s("Enter the Element : \n");
				scanf_s("%d", &option);
				if (MyStaticBinaryHeap_Push(&myHeap, &option))
				{
					printf_s("Element inserted successfully\n");
				}
				else { printf_s("Failed at inserting element\n"); }
				break;
			}
			default:
			{
				printf("invalid option\n");
			}
		}
	}
}