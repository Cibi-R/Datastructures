#include <include.h>
#include DOUBLE_LIST_H



void Execute_Double_List(void)
{
	unsigned char Option;

	MyDoubleList* MyList = GetMyDoubleList();

	printf_s("***  Double List ***\n");

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
			DoubleList_TraverseElement(MyList);
			break;
		}
		}
	}
}