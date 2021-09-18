#include <include.h>
#include SINGLE_LIST_STATIC_H

void MyStaticLlist_Init(MyListStatic* MyList)
{
	MyList->top = -1;

	memset(MyList->Buffer, 0, SINGLE_LIST_STATIC_MAX_SIZE);
}

static unsigned char IsListFull(MyListStatic *MyList)
{
	uint8_t retVal = 0;

	if ((SINGLE_LIST_STATIC_MAX_SIZE - 1) == MyList->top)
	{
		return 1;
	}
	
	return retVal;
}

static unsigned char IsListEmpty(MyListStatic *MyList)
{
	uint8_t retVal = 0;

	if (MyList->top == -1)
	{
		return 1;
	}
	
	return retVal;
}

unsigned char MyStaticList_PushElement(MyListStatic *MyList, SINGLE_LIST_STATIC_ELEMENT_TYPE Element)
{
	uint8_t retVal = 1;

	if (IsListFull(MyList))
	{
		retVal = 0;
	}
	else
	{
		MyList->top++;

		MyList->Buffer[MyList->top] = Element;
	}

	return retVal;
}


unsigned char MyStaticList_PopElement(MyListStatic* MyList, SINGLE_LIST_STATIC_ELEMENT_TYPE* Element)
{
	unsigned char retVal = 1;

	if (!IsListEmpty(MyList))
	{
		*Element = MyList->Buffer[MyList->top];

		MyList->top--;
	}
	else
	{
		retVal = 0;
	}

	return retVal;
}

unsigned char MyStaticList_InsertElement(MyListStatic *MyList, SINGLE_LIST_STATIC_ELEMENT_TYPE Element, int16_t Position)
{
	unsigned char retVal = 0;

	if (!IsListFull(MyList))
	{
		/*< list should not overflow and Position value should be within the top + 1 element */
		if ((SINGLE_LIST_STATIC_MAX_SIZE > (MyList->top + 1)) && ((MyList->top + 1) >= Position))
		{
			for (int16_t i = MyList->top; i >= Position; i--)
			{
				MyList->Buffer[i + 1] = MyList->Buffer[i];
			}

			MyList->Buffer[Position] = Element;

			MyList->top++;

			retVal = 1;
		}

		return retVal;
	}

	return retVal;
}


unsigned char MyStaticList_RemoveElement(MyListStatic* MyList, SINGLE_LIST_STATIC_ELEMENT_TYPE* Element, int16_t Position)
{
	unsigned char retVal = 0;

	if (!IsListEmpty(MyList))
	{
		if (Position <= MyList->top)
		{
			*Element = MyList->Buffer[MyList->top];

			for (int16_t i = Position; i < MyList->top; i++)
			{
				MyList->Buffer[i] = MyList->Buffer[i + 1];
			}

			MyList->top--;

			retVal = 1;
		}
	}

	return retVal;
}

void MyStaticList_Traverse(MyListStatic *MyList)
{
	if (IsListEmpty(MyList))
	{
		printf_s("list is empty...!\n");
	}

	else
	{
		for (int16_t i = 0; i <= MyList->top; i++)
		{
			printf_s("Element[%d] = %d\n", i, MyList->Buffer[i]);
		}
	}
}
