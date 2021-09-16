#include <include.h>
#include SINGLE_LIST_H

void UnitTest1_MySingleList(void)
{
	unsigned int option,Pos;

	MySingleList* MyList = NULL;

	printf(" ****************************************************************************************************\n \
		                        My Static queue Unit Test 1                                           \n \
****************************************************************************************************\n");

	if (MySingleList_Create(&MyList, sizeof(unsigned int)))
	{
		while (1)
		{
			printf_s("### Single List ###\n");
			printf_s("1. Push Element\n2. Pop Element\n3. Insert Element\n4. Remove Element\n5. Traverse List\n");
			printf_s("6. Get Element\n");
			scanf_s("%d", &option);

			switch (option)
			{
				case 1:
				{
					printf_s("Enter the Element : \n");
					scanf_s("%d", &option);
					if (MySingleList_PushElement(MyList, &option))
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
					if (MySingleList_PopElement(MyList, &option))
					{
						printf_s("Popped Element : %d\n", option);
					}
					else
					{
						printf_s("Pop failed\n");
					}
					break;
				}

				case 3:
				{
					printf_s("Enter the Position : \n");
					scanf_s("%d", &Pos);
					printf_s("Enter the Element : \n");
					scanf_s("%d", &option);

					if (MySingleList_InsertElement(MyList, &option, Pos))
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

					if (MySingleList_RemoveElement(MyList, &option, Pos))
					{
						printf_s("Removed element : %d\n", option);
						break;
					}
					else { printf_s("Failed to remove element!\n"); }
					break;
				}

				case 5:
				{
					MySingleList_Traverse(MyList);
					break;
				}

				case 6:
				{
					printf_s("Enter the position : \n");
					scanf_s("%d", &Pos);

					if (MySingleList_GetElement(MyList, &option, Pos))
					{
						printf_s("element value : %d\n", option);
					}
					else
					{
						printf_s("failed to retrieve element\n");
					}
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

