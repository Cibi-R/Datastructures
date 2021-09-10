#include <include.h>
#include QUEUE_STATIC_H


void UnitTest1_MyStaticQueue(void)
{
	MyQueueStatic MyQueue;

	unsigned char Option;

	/*< initialize the static queue */
	MyStaticQueue_Init(&MyQueue);

	while (1)
	{
		printf_s("/***  Static Queue  ***/\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Traverse\n");
		scanf_s("%d", &Option);

		switch (Option)
		{
			case 1:
			{
				printf_s("enter element : \n");
				scanf_s("%d", &Option);

				if (MyStaticQueue_EnQueue(&MyQueue, Option))
				{
					printf_s("element inserted successfully!\n");
				}
				else 
				{ 
					printf_s("enqueue operation failed, queue may be full...\n"); 
				}
				break;
			}	
			case 2:
			{
				if (MyStaticQueue_DeQueue(&MyQueue, &Option))
				{
					printf_s("dequeued element : %d\n", Option);
				}
				else
				{
					printf_s("dequeue operation failed, queue may be empty...\n");
				}
				break;
			}
			case 3:
			{
				if (MyStaticQueue_Peek(&MyQueue, &Option))
				{
					printf_s("peek element : %d\n", Option);
				}
				else
				{
					printf_s("peek operation failed, queue may be empty...\n");
				}
				break;
			}
			case 4:
			{
				MyStaticQueue_Traverse(&MyQueue);
				break;
			}
			default:
			{
				printf_s("Invalid Option!\n");
				break;
			}
		}
	}
}