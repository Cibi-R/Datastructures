#include <include.h>
#include SINGLE_LIST_H

void Execute_Single_List(void)
{
	unsigned int Option,Pos;

	MySingleList* MyList = GetSingleList();

	while (1)
	{
		printf_s("/*** Single List ***/\n");
		printf_s("1. Push Element\n2. Pop Element\n3. Insert Element\n4. Remove Element\n5. Traverse List\n");
		printf_s("6. Get Element\n");
		scanf_s("%d", &Option);

		switch (Option)
		{
			case 1:
			{
				printf_s("Enter the Element : \n");
				scanf_s("%d", &Option);
				if (SingleList_PushElement(MyList, Option))
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
				printf_s("Popped Element : %d\n", SingleList_PopElement(MyList));
				break;
			}

			case 3:
			{
				printf_s("Enter the Position : \n");
				scanf_s("%d", &Pos);
				printf_s("Enter the Element : \n");
				scanf_s("%d", &Option);

				if (SingleList_InsertElement(MyList, Option, Pos))
				{
					printf_s("Element Inserted successfully!\n");
					break;
				}
				else { printf_s("Failed to insert an element!\n"); }
				break;
			}

			case 4:
			{
				printf_s("Enter the Position : \n");
				scanf_s("%d", &Pos);
				printf_s("Removed Element : %d\n", SingleList_RemoveElement(MyList, Pos));
				break;
			}

			case 5:
			{
				SingleList_Travese(MyList);
				break;
			}
			
			case 6:
			{
				printf_s("Enter the Position : \n");
				scanf_s("%d", &Pos);
				printf_s("Element : %d\n",SingleList_GetElement(MyList,Pos));
				break;
			}
		}
	}
}

