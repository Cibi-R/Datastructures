#include <include.h>
#include DOUBLE_LIST_H



void Execute_Double_List(void)
{
	DOUBLE_LIST_ELEMENT_TYPE Element;

	uint32_t Option, Position;

	MyDoubleList* MyList = GetMyDoubleList();

	printf_s("***  Double List ***\n");

	while (1)
	{
		printf_s("1. Push Element\n2. Pop Element\n3. Insert Element\n4. Remove Elements\n5.Traverse Elements\n");
		scanf_s("%d", &Option);

		switch (Option)
		{
		case 1:
		{
			printf_s("Enter the Element : \n");
			scanf_s("%d", &Option);
			if (DoubleList_PushElement(MyList, Option))
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
			if (DoubleList_PopElement(MyList, &Element))
			{
				printf("Removed Element from the double list : %d\n", Element);
			}
			else
			{
				printf("Double list is empty\n");
			}
			break;
		}

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

		case 5:
		{
			DoubleList_TraverseElement(MyList);
			break;
		}
		}
	}
}