#include <include.h>
#include QUEUE_STATIC_H


void Execute_Queue_Static(void)
{
	unsigned char Option;

	while (1)
	{
		printf_s("/***  Static Queue  ***/\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Traverse\n");
		scanf_s("%d", &Option);
		switch (Option)
		{
			case 1:
			{
				printf_s("Enter Element : ");
				scanf_s("%d", &Option);
				if (Enqueue(Option))
				{
					printf_s("Element inserted successfully!\n");
				}
				else { printf_s("Queue full!\n"); }
				break;
			}	
			case 2:
			{
				printf_s("Dequeued element : %d\n", Dequeue());
				break;
			}
			case 3:
			{
				printf_s("Peek element : %d\n", Queue_Peek());
				break;
			}
			case 4:
			{
				Queue_Traverse();
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

