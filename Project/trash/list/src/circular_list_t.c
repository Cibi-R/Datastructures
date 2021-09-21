#include <include.h>
#include CIRCULAR_LIST_H


void UnitTest1_MyCircularList(void)
{
	uint32_t Option, Position;

	MyCircularSinglyList* MyCircularList;

	MyCircularList_Create(&MyCircularList, sizeof(unsigned int));

	printf(" ****************************************************************************************************\n \
		                        My singly circular list Unit Test 1                                       \n \
****************************************************************************************************\n");

	if (NULL != MyCircularList)
	{
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

					if (MyCircularList_PushElement(MyCircularList, &Option))
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
				if (MyCircularList_PopElement(MyCircularList, &Option))
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

				if (MyCircularList_InsertElement(MyCircularList, &Option, Position))
				{
					printf("Element inserted : %d\n", Option);
				}
				else
				{
					printf("Element insertion failed\n");
				}
				break;
			}
#if 0
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
#endif
				case 5:
				{
					MyCiruclarList_Traverse(MyCircularList);
					break;
				}

				default:
				{
					break;
				}
			}
		}
	}
}