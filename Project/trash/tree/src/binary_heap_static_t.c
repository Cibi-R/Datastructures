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
		printf_s("1. Insert Element\n2. Traverse element\n3. Pop element\n4. Insert automatic\n");
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
			case 2:
			{
				MyStaticBinaryHeap_Traverse(&myHeap);
				break;
			}
			case 3:
			{
				if (MyStaticBinaryHeap_Pop(&myHeap, &option))
				{
					printf("popped element : %d\n", option);
				}
				else
				{
					printf("element pop failed\n");
				}
				break;
			}
			case 4:
			{
				int start;
				int end;
				int periodicity;

				printf("enter start : \n");
				scanf("%d", &start);
				printf("enter end : \n");
				scanf("%d", &end);
				printf("periodicity : ");
				scanf("%d", &periodicity);

				for (;start <= end; start = periodicity + start)
				{
					if (!MyStaticBinaryHeap_Push(&myHeap, &start))
					{
						break;
					}
				}
				
				printf("elements pushed successfully\n");
				break;
			}
			default:
			{
				printf("invalid option\n");
			}
		}
	}
}