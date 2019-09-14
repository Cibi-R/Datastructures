#include <include.h>
#include SINGLE_LIST_STATIC_H


void Execute_Single_List_Static(void)
{
	unsigned char Option,i;

	while (1)
	{
		printf_s("1. Push Element.\n2. Pop Element\n3. Insert Element\n4. Remove Element\n5. Traverse List\n");
		scanf_s("%d", &Option);

		switch (Option)
		{
		case 1:
			printf_s("Enter the Element : \n");
			scanf_s("%d", &Option);

			if (PushElement(Option))
			{
				printf_s("Element Inserted Successfully!\n");
			}
			else
			{
				printf_s("Element not inserted!\n");
			}
			break;
		case 2:
			printf_s("Popped Element : %d\n", PopElement());
			break;
		case 3:
			printf_s("Enter the Element : \n");
			scanf_s("%d", &Option);
			printf_s("Enter the Position : \n");
			scanf_s("%d", &i);

			if (InsertElement(Option, i))
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
			printf_s("Removed Element : %d\n", RemoveElement(i));
			break;
		case 5:
			Traverse_Single_Static_List();
			break;
		default:
			break;
		}
	}
}

