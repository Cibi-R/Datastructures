#include <include.h>
#include SINGLE_LIST_STATIC_H


void UnitTest1_MySingleList_Static(void)
{
	MyListStatic MyList;

	MyStaticLlist_Init(&MyList);

	unsigned char option,i;

	while (1)
	{
		printf_s("1. Push Element.\n2. Pop Element\n3. Insert Element\n4. Remove Element\n5. Traverse List\n");
		scanf_s("%d", &option);

		switch (option)
		{
		case 1:
			printf_s("Enter the Element : \n");
			scanf_s("%d", &option);

			if (MyStaticList_PushElement(&MyList, option))
			{
				printf_s("Element Inserted Successfully!\n");
			}
			else
			{
				printf_s("Element not inserted!\n");
			}
			break;

		case 2:
			if (MyStaticList_PopElement(&MyList, &option))
			{
				printf_s("Popped Element : %d\n", option);
			}
			else
			{
				printf_s("element pop failed\n");
			}
			break;

		case 3:
			printf_s("Enter the Element : \n");
			scanf_s("%d", &option);

			printf_s("Enter the Position : \n");
			scanf_s("%d", &i);

			if (MyStaticList_InsertElement(&MyList, option, i))
			{
				printf_s("Element inserted successfully\n");
			}
			else
			{
				printf_s("Element not inserted\n");
			}
			break;

		case 4:
			printf_s("Enter the Position : \n");
			scanf_s("%d", &i);

			if (MyStaticList_RemoveElement(&MyList, &option, i))
			{
				printf_s("Removed Element : %d\n", i);
			}
			else
			{
				printf_s("Element remove failed\n");
			}
			break;

		case 5:
			MyStaticList_Traverse(&MyList);
			break;

		default:
			printf_s("invalid option...\n");
			break;
		}
	}
}

