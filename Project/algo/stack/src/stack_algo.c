#include <Include.h>
#include STACK_STATIC_H
#include STACK_DYNAMIC_H
#include SINGLE_LIST_H

//20. Valid Parentheses
bool isValid(char* s) 
{
	char compareValue = 0, retVal = 0;

	MyDynamicStack* MyStack;

	MyDynamicStack_Create(&MyStack, sizeof(char));

	while (*s)
	{
#if 1
		if (('(' == *s) || ('{' == *s) || ('[' == *s))
		{
			MyDynamicStack_Push(MyStack, s);
		}
		else
		{
			if (MyDynamicStack_Peek(MyStack, &retVal))
			{
				if (
					(
						(('(' == retVal) && (')' == *s)) ||
						(('{' == retVal) && ('}' == *s)) ||
						(('[' == retVal) && (']' == *s))
						)
					)
				{
					MyDynamicStack_Pop(MyStack, NULL);
				}
				else
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
		}
		s++;
#endif
	}

	if (!MyDynamicStack_Is_Empty(MyStack))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

//32. Longest Valid Parentheses
int longestValidParentheses(char* s) 
{
	char value = 0;
	bool validString = 0;

	MyDynamicStack* MyStack = NULL;

	MyDynamicStack_Create(&MyStack, sizeof(char));

	int16_t subStringCount = 0;
	int16_t currCount = 0;

	while (*s)
	{
		if ('(' == *s)
		{
			MyDynamicStack_Push(MyStack, s);
		}
		else
		{
			if (MyDynamicStack_Peek(MyStack, &value))
			{
				if ('(' == value)
				{
					currCount += 2;

					if (currCount > subStringCount)
					{
						subStringCount = currCount;
					}

					if (!validString)
					{
						validString = 1;
					}
				}
				else
				{
					currCount = 0;
				}
			}

			MyDynamicStack_Push(MyStack, s);
		}
		s++;
	}

	return subStringCount;
}

//234. Palindrome Linked List
bool isPalindrome(void)
{
#if 0 // C++ solution
	class Solution {
	public:
		bool isPalindrome(ListNode* head)
		{
			bool retVal = true;
			ListNode* temp = head;
			stack<int> myStack;

			do
			{
				myStack.push(temp->val);

				temp = temp->next;
			} while (temp != NULL);

			temp = head;

			do
			{
				if (myStack.top() != temp->val)
				{
					retVal = false;

					break;
				}
				temp = temp->next;

				myStack.pop();
			} while (temp != NULL);

			return retVal;
		}
	};
#endif
}

bool backspaceCompare(char* s, char* t) 
{
	unsigned char retVal = 0;

	uint16_t stackLength;

	MyDynamicStack* sString;
	MyDynamicStack* tString;

	MyDynamicStack_Create(&sString, sizeof(char));
	MyDynamicStack_Create(&tString, sizeof(char));

	while (*s)
	{
		if ('#' == *s)
		{
			MyDynamicStack_Pop(sString, NULL);
		}
		else
		{
			MyDynamicStack_Push(sString, s);
		}

		s++;
	}

	//MyDynamicStack_Traverse(sString);

	while (*t)
	{
		if ('#' == *t)
		{
			MyDynamicStack_Pop(tString, NULL);
		}
		else
		{
			MyDynamicStack_Push(tString, t);
		}

		t++;
	}

	//MyDynamicStack_Traverse(tString);

	stackLength = MyDynamicStack_Length(sString);

	if (stackLength == MyDynamicStack_Length(tString))
	{
		int i;
		char val1, val2;

		for (i = 0; i < stackLength; i++)
		{
			MyDynamicStack_Pop(sString, &val1);
			MyDynamicStack_Pop(tString, &val2);

			if (val1 != val2)
			{
				break;
			}
		}

		if (i == stackLength)
		{
			retVal = 1;
		}
	}

	return retVal;
}

void Algo_Stack(void)
{
#if 0
	char* s = "[";
	(isValid(s)) ? printf("valid\n") : printf("not valid\n");
#endif

#if 0
	char* s = "()(())";
	printf("longest valid string count : %d\n", longestValidParentheses(s));
#endif

#if 1
	char* s = "ab##";
	char* t = "c#d#";
	printf("return value : %d\n", backspaceCompare(s, t));
#endif
}