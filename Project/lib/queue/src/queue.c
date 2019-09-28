#include <include.h>
#include QUEUE_STATIC_H

QUEUE_ELEMENT_TYPE Queue[QUEUE_MAX_SIZE];

static int16_t Front = QUEUE_EMPTY;
static int16_t Rear = QUEUE_EMPTY;

static unsigned char IsQueueFull(void)
{
	if (Front == ((Rear + 1) % QUEUE_MAX_SIZE))
	{
		return 1;
	}
	return 0;
}

static unsigned char IsQueueEmpty(void)
{
	if ((Front == QUEUE_EMPTY) && (Rear == QUEUE_EMPTY))
	{
		return 1;
	}
	return 0;
}

unsigned char Enqueue(QUEUE_ELEMENT_TYPE Element)
{
	if (IsQueueFull())
	{
		return 0;
	}

	else if (IsQueueEmpty())
	{
		Front = 0;
		Rear = 0;
	}

	else
	{
		Rear++;

		if (Rear == QUEUE_MAX_SIZE) { Rear == 0; }
	}

	Queue[Rear] = Element;

	return 1;
}

QUEUE_ELEMENT_TYPE Dequeue(void)
{
	QUEUE_ELEMENT_TYPE RetElement = (QUEUE_ELEMENT_TYPE)0;

	if (!IsQueueEmpty())
	{   
		RetElement = Queue[Front];

		if (Front == Rear)
		{
			Front = QUEUE_EMPTY;
			Rear = QUEUE_EMPTY;
		}

		else
		{
			Front++;

			if (Front == QUEUE_MAX_SIZE) { Front = 0; }
		}
	}

	return RetElement;
}

QUEUE_ELEMENT_TYPE Queue_Peek(void)
{
	if (IsQueueEmpty())
	{
		return (QUEUE_ELEMENT_TYPE)0;
	}

	else
	{
		return Queue[Front];
	}
}

void Queue_Traverse(void)
{
	unsigned char i = Front;

	if (IsQueueEmpty())
	{
		printf("Queue is empty!\n");
	}

	else if (Front == Rear)
	{
		printf("Queue Index : [%d], Queue Element : [%d]\n", i, Queue[i]);
	}

	else
	{
		do
		{
			printf("Queue Index : [%d], Queue Element : [%d]\n", i, Queue[i]);

			i++;

			if (i == QUEUE_MAX_SIZE)
			{
				i = 0;
			}
		} while (Rear != i);

		printf("Queue Index : [%d], Queue Element : [%d]\n", i, Queue[i]);
	}
}