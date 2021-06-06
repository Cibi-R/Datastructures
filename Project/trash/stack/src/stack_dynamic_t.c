#include <include.h>
#include STACK_DYNAMIC_H
#include STACK_DYNAMICt_H


void UnitTest1_MyDynamicStack(void)
{
	int option, value1;
	MyDynamicStack* myStack = NULL;

	printf(" ****************************************************************************************************\n \
		                        My Dynamic statck Unit Test 1                                           \n \
****************************************************************************************************\n");

	if (GetMyDynamicStack(&myStack));
	{
		while (1)
		{
			printf("### Enter the option ###\n1. Push Element\n2. Pop Element\n3. Peek Element\n4. Traverse stack\n");
			scanf("%d", &option);
			switch (option)
			{
				case 1:
				{
					printf("Enter the element : \n");
					scanf("%d", &value1);
					if (PushMyDynamicStack(myStack, value1))
					{
						printf("Element pushed to the stack : %d\n", value1);
					}
					else
					{
						printf("Push operation failed\n");
					}
					break;
				}

				case 2:
				{
					if (PopMyDynamicStack(myStack, &value1))
					{
						printf("Element popped succesfully : %d\n", value1);
					}
					else
					{
						printf("Failed to pop element\n");
					}
					break;
				}

				case 3:
				{
					if (PeekMyDynamicStack(myStack, &value1))
					{
						printf("Peek element : %d\n", value1);
					}
					else
					{
						printf("Failed to get peek element\n");
					}
					break;
				}

				case 4:
				{
					TraverseMyDynamicStack(myStack);
					break;
				}

				default:
				{
					printf("invalid option\n");
					break;
				}
			}
		}
	}
}

/*
 * Get Min Element.
 */

//STACK_ELEMENT_TYPE_DYNAMIC GetMinElement(MyStack* obj)
//{
//	STACK_ELEMENT_TYPE_DYNAMIC RetVal = 0;
//
//	if (obj != NULL)
//	{
//		MyStack* Temp = obj->Next;
//
//		RetVal = Temp->Element;
//
//		while (Temp->Next)
//		{
//			Temp = Temp->Next;
//			RetVal = (RetVal > Temp->Element) ? Temp->Element : RetVal;
//		}
//	}
//
//	return RetVal;
//}

#if 0
unsigned char isValid(char* s)
{
	MyStack *StringStack = Get_MyStack();

	unsigned char Return_Value = 0;

	if (s == NULL)
	{
		Return_Value = 1;
	}

	else
	{
		while (*s)
		{
			switch (*s)
			{
			case ')':
			{
				(Peek_MyStack(StringStack) != '(') ? Push_MyStack(StringStack,*s) : Pop_MyStack(StringStack);
				break;
			}
			case '}':
			{
				(Peek_MyStack(StringStack) != '{') ? Push_MyStack(StringStack, *s) : Pop_MyStack(StringStack);
				break;
			}
			case ']':
			{
				(Peek_MyStack(StringStack) != '[') ? Push_MyStack(StringStack, *s) : Pop_MyStack(StringStack);
				break;
			}
			default:
			{
				Push_MyStack(StringStack, *s);
				break;
			}
			}
			s++;
		}
	}

	if (Peek_MyStack(StringStack) == 0)
	{
		Return_Value = 1;
	}

	Delete_MyStack(StringStack);

	return Return_Value;
}

void CheckIsValid(char* str)
{
	if (isValid(str))
	{
		printf_s("Valid String\n");
	}

	else
	{
		printf_s("Invalid String\n");
	}
}

char* removeOuterParentheses(char* S)
{
	MyStack *strStack = Get_MyStack();

	MyStack* ResultStack = Get_MyStack();

	char Popped_Char,Peek_Char;

	if (*S)
	{
		while (*S)
		{
			Peek_Char = Peek_MyStack(strStack);

			if (*S == '(')
			{
				Push_MyStack(strStack, '(');
			}

			else
			{
				Popped_Char = Pop_MyStack(strStack);

				if (Peek_MyStack(strStack) != 0)
				{

				}
			}
			S++;
		}
	}

	else
	{

	}
}

// [3,5,0,3,4]
unsigned char find132pattern(int* nums, int numsSize)
{
	int FirstElement = 0;

	MyStack *Stack = Get_MyStack();

	int i;

	for (i = 0; i < numsSize; i++)
	{
		if (!Peek_MyStack(Stack))
		{
			Push_MyStack(Stack,nums[i]);
		}

		else if (Peek_MyStack(Stack) > nums[i])
		{
			if ((GetSize_MyStack(Stack) >= 2) && (FirstElement < nums[i]))
			{
				return 1;
			}
			else
			{
				while (!Peek_MyStack(Stack))
				{
					Pop_MyStack(Stack);
				}

				FirstElement = nums[i];

				Push_MyStack(Stack, nums[i]);
			}
		}

		else
		{
			Push_MyStack(Stack,nums[i]);
		}
	}

	return 0;
}

/*
 * Remove Adjacent String.
 */

void String_Reverse(char* str)
{
	int i = 0;
	int j = strlen(str) - 1;

	if (j > 0)
	{
		while (i < j)
		{
			str[i] ^= str[j];
			str[j] ^= str[i];
			str[i] ^= str[j];

			i++;
			j--;
		}
	}
}

char* removeDuplicates(char* S)
{
	unsigned int i;

	MyStack* NewStack = Get_MyStack();

	while (*S)
	{
		if ((Peek_MyStack(NewStack)) == *S)
		{
			Pop_MyStack(NewStack);
		}
		else
		{
			Push_MyStack(NewStack,*S);
		}
		S++; 
	}

	for (i = 0; Peek_MyStack(NewStack); i++)
	{
		S[i] = Pop_MyStack(NewStack);
	}

	S[i] = '\0';

	String_Reverse(S);

	printf_s("%s", S);

	return S;
}
#endif