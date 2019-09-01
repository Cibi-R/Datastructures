#include <include.h>
#include QUEUE_DYNAMIC_H


void Execute_MyQueue(void)
{
	unsigned int Option;

	MyQueue* NewQueue;

	NewQueue = GetMyQueue();

	while (1)
	{
		printf_s("1. Enqueue\n2. Dequeue\n3. Peek\n4. Traverse\n");
		scanf_s("%d", &Option);

		switch (Option)
		{
		case 1:
			printf("Enter the Element:");
			scanf_s("%d", &Option);
			(MyQueue_Enqueue(NewQueue,Option)) ? printf_s("Element Enqueued Successfully!\n") : printf_s("Enqueue Operation failed!\n");
			break;

		case 2:
			printf("Dequeued Element : %d\n", MyQueue_Dequeue(NewQueue));
			break;

		case 3:
			//printf("Peek Element : %d\n", Stack_Peek());
			break;

		case 4:
			MyQueue_Traverse(NewQueue);
			break;
		}
	}
}