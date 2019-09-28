#include <include.h>
#include CIRCULAR_LIST_H


void Execute_Circular_List(void)
{
	unsigned char Option;

	MyCircularList* MyList = GetCircularList();

	while (1)
	{
		printf_s("1. Insert Element\n2. Traverse Element\n");
		scanf_s("%d", &Option);

		switch (Option)
		{
			case 1:
			{
				printf_s("Enter the Element : \n");
				scanf_s("%d", &Option);
				if (CircularList_PushElement(MyList,Option))
				{
					printf_s("Element Inserted Successfully!\n");
				}
				else
				{
					printf_s("Element is not inserted!\n");
				}
				break;
			}

			case 2:
			{
				CircularList_Traverse(MyList);
				break;
			}
		}
	}
}