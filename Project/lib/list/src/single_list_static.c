#include <include.h>
#include SINGLE_LIST_STATIC_H

static SINGLE_LIST_STATIC_ELEMENT_TYPE Single_List_Static[SINGLE_LIST_STATIC_MAX_SIZE];
static int Top = -1;

static unsigned char IsListFull(void)
{
	if (Top == (SINGLE_LIST_STATIC_MAX_SIZE - 1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

static unsigned char IsListEmpty(void)
{
	if (Top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

unsigned char PushElement(SINGLE_LIST_STATIC_ELEMENT_TYPE Element)
{
	if (IsListFull())
	{
		return 0;
	}
	else
	{
		Top++;
	}

	Single_List_Static[Top] = Element;

	return 1;
}

SINGLE_LIST_STATIC_ELEMENT_TYPE PopElement(void)
{
	SINGLE_LIST_STATIC_ELEMENT_TYPE RetVal = 0;

	if (!IsListEmpty())
	{
		RetVal = Single_List_Static[Top];
		Top--;
	}

	return RetVal;
}

unsigned char InsertElement(SINGLE_LIST_STATIC_ELEMENT_TYPE Element,unsigned char Position)
{
	unsigned char RetVal = 0;
	int i;

	if (IsListFull())
	{
		/* Do nothing */
	}

	else if (Position <= (Top + 1))
	{
		for (i = Top; i >= Position; i--)
		{
			Single_List_Static[i + 1] = Single_List_Static[i];
		}
		Single_List_Static[Position] = Element;

		Top++;

		RetVal = 1;
	}

	else
	{
		/* Do nothing */
	}

	return RetVal;
}

SINGLE_LIST_STATIC_ELEMENT_TYPE RemoveElement(unsigned char Position)
{
	SINGLE_LIST_STATIC_ELEMENT_TYPE RetElement = 0;

	int i;

	if (IsListEmpty())
	{
		/* Do nothing */
	}

	else if (Position <= Top)
	{
		RetElement = Single_List_Static[Position];

		Top--;

		for (i = Position; i <= Top; i++)
		{
			Single_List_Static[i] = Single_List_Static[i+1];
		}
	}

	else
	{
		/* Do nothing */
	}

	return RetElement;
}

void Traverse_Single_Static_List(void)
{
	unsigned char i;

	if (IsListEmpty())
	{
		printf_s("List is Empty!\n");
	}

	else
	{
		for (i = 0; i <= Top; i++)
		{
			printf_s("Element[%d] = %d\n", i, Single_List_Static[i]);
		}
	}
}
