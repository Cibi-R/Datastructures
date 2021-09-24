#include <include.h>
#include DOUBLE_LIST_H



void UnitTest1_MyDoubleList(void)
{
	uint32_t option, position;

	MyDoubleList* MyList;

	MyDoubleList_Create(&MyList, sizeof(unsigned int));

	printf(" ****************************************************************************************************\n \
		                        My double list Unit Test 1                                           \n \
****************************************************************************************************\n");

	while (1)
	{
		printf_s("### Double List ###\n");
		printf_s("1. Push Element\n2. Pop Element\n3. Insert Element\n4. Remove Element\n5. Traverse List\n");
		printf_s("6. Get Element\n");
		scanf_s("%d", &option);

		switch (option)
		{
			case 1:
			{
				printf_s("Enter the Element : \n");
				scanf_s("%d", &option);
				if (MyDoubleList_PushElement(MyList, &option))
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
			if (MyDoubleList_PopElement(MyList, &option))
			{
				printf("Removed Element from the double list : %d\n", option);
			}
			else
			{
				printf("Double list is empty\n");
			}
			break;
		}
#if 0
		case 3:
		{
			printf_s("Enter the Element : \n");
			scanf_s("%d", &Option);
			printf_s("Enter the Position : \n");
			scanf_s("%d", &Position);
			if (DoubleList_InsertElement(MyList, Option, Position))
			{
				printf_s("Element Inserted Successfully!\n");
			}
			else
			{
				printf_s("Element is not inserted!\n");
			}
			break;
		}

		case 4:
		{
			printf_s("Enter the Position : \n");
			scanf_s("%d", &Position);
			if (DoubleList_RemoveElement(MyList, &Element, Position))
			{
				printf("Removed Element from the double list : %d\n", Element);
			}
			else
			{
				printf("Double list is empty (or) Position out of boundary\n");
			}
			break;
		}
#endif
			case 5:
			{
				MyDoubleList_Traverse(MyList);
				break;
			}
		}
	}
}