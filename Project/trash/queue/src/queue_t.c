#include <include.h>
#include QUEUE_STATIC_H


static MyQueueStatic MyQueue;

void UnitTest1_MyStaticQueue(void)
{
	unsigned int option;
	unsigned char value;

	/*< initialize the static queue */
	MyStaticQueue_Init(&MyQueue);

	printf(" ****************************************************************************************************\n \
		                        My Static queue Unit Test 1                                           \n \
****************************************************************************************************\n");

	while (1)
	{
		printf_s("###  Enter the option  ###/\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Traverse\n");
		scanf("%d", &option);

		switch (option)
		{
			case 1:
			{
				printf_s("enter element : \n");
				scanf_s("%d", &value);

				if (MyStaticQueue_EnQueue(&MyQueue, value))
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
				if (MyStaticQueue_DeQueue(&MyQueue, &value))
				{
					printf_s("dequeued element : %d\n", value);
				}
				else
				{
					printf_s("dequeue operation failed, queue may be empty...\n");
				}
				break;
			}
			case 3:
			{
				if (MyStaticQueue_Peek(&MyQueue, &value))
				{
					printf_s("peek element : %d\n", value);
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