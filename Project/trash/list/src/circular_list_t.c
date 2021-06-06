#include <include.h>
#include CIRCULAR_LIST_H


void Execute_Circular_Singly_List(void)
{
	uint32_t Option, Position;

	MyCircularSinglyList* MyList = GetCircularSinglyList();

	while (1)
	{
		printf_s("1. Push Element\n2. Pop Element\n3. Insert Element\n4. Remove Element\n5. Traverse Element\n");
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
				if (CircularList_PopElement(MyList, &Option))
				{
					printf_s("Element popped Successfully  %d\n", Option);
				}
				else
				{
					printf_s("list is empty!\n");
				}
				break;
			}

			case 3:
			{
				printf_s("Enter the Element : \n");
				scanf_s("%d", &Option);
				printf_s("Enter the Position : \n");
				scanf_s("%d", &Position);

				if (CircularList_InsertElement(MyList, Option, Position))
				{
					printf("Element inserted : %d\n", Option);
				}
				else
				{
					printf("Element insertion failed\n");
				}
				break;
			}
			case 4:
			{
				printf_s("Enter the Position : \n");
				scanf_s("%d", &Position);

				if (CircularList_RemoveElement(MyList, &Option, Position))
				{
					printf("Removed element : %d\n", Option);
				}
				else
				{
					printf("Element removal failed\n");
				}
				break;
			}
			case 5:
			{
				CircularList_Traverse(MyList);
				break;
			}
		}
	}
}