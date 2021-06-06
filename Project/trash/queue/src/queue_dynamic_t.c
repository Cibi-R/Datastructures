#include <include.h>
#include QUEUE_DYNAMIC_H

void UnitTest1_MyDynamicQueue(void)
{
	int option, value1;
	MyDynamicQueue* myQueue = NULL;

	printf(" ****************************************************************************************************\n \
		                        My Dynamic Queue Unit Test 1                                          \n \
****************************************************************************************************\n");

	if (GetMyDynamicQueue(&myQueue));
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
					if (EnQueueMyDynamicQueue(myQueue, value1))
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
					if (DeQueueMyDynamicQueue(myQueue, &value1))
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
					if (PeekMyDynamicQueue(myQueue, &value1))
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
					TraverseMyDynamicQueue(myQueue);
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