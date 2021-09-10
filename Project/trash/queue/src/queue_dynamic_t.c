#include <include.h>
#include QUEUE_DYNAMIC_H

void UnitTest1_MyDynamicQueue(void)
{
	unsigned int option, value1;

	MyDynamicQueue* myQueue = NULL;

	printf(" ****************************************************************************************************\n \
		                        My Dynamic Queue Unit Test 1                                          \n \
****************************************************************************************************\n");

	if (MyDynamicQueue_Create(&myQueue, sizeof(unsigned int)))
	{
		while (1)
		{
			printf("### Enter the option ###\n1. Enqueue Element\n2. Dequeue Element\n3. Peek Element\n4. Traverse queue\n");
			scanf("%d", &option);
			switch (option)
			{
				case 1:
				{
					printf("Enter the element : \n");
					scanf("%d", &value1);

					if (MyDynamicQueue_EnQueue(myQueue, (void*)&value1))
					{
						printf("Element enqueued to the queue : %d\n", value1);
					}
					else
					{
						printf("enqueue operation failed\n");
					}
					break;
				}
				case 2:
				{
					if (MyDynamicQueue_DeQueue(myQueue, (void*)&value1))
					{
						printf("Element De-Queued succesfully : %d\n", value1);
					}
					else
					{
						printf("Failed to de-queue element\n");
					}
					break;
				}
				case 3:
				{
					if (MyDynamicQueue_Peek(myQueue, (void*)&value1))
					{
						printf("Peek element : %d\n", value1);
					}
					else
					{
						printf("Failed to get peek element\n");
					}
					break;
				}
				case 4:
				{
					MyDynamicQueue_Traverse(myQueue);
					break;
				}
				default:
				{
					printf("invalid option\n");
					break;
				}
			}
		}
	}
}