#include <Include.h>
#include SINGLE_LIST_H



#if 0
 struct ListNode {
     int val;
     struct ListNode *next;
 };


void InsertNode(struct ListNode** firstNode, int value)
{
    /*< if InserNode is called it is assumed list that the list is not empty */
    struct ListNode* tempNode = NULL;

    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;

    if (*firstNode == NULL)
    {
        (*firstNode) = newNode;
    }
    else
    {
        tempNode = *firstNode;

        while (tempNode->next != NULL)
        {
            tempNode = tempNode->next;
        }
        tempNode->next = newNode;
    }
}


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* outNode = NULL;

    if (l1 == NULL)
    {
        outNode = l2;
    }
    else if (l2 == NULL)
    {
        outNode = l1;
    }
    else
    {
        int data1, data2;

        while ((l1 != NULL) || (l2 != NULL))
        {
            if (l1 != NULL) { data1 = l1->val; }
            if (l2 != NULL) { data2 = l2->val; }

            if (data1 == data2)
            {
                InsertNode(&outNode, data1);
                InsertNode(&outNode, data2);

                if (l1->next == NULL)
                {
                    data1 = 101;
                }

                if (l2->next == NULL)
                {
                    data2 = 101;
                }

                l1 = l1->next;
                l2 = l2->next;
            }

            else if (data1 < data2)
            {
                InsertNode(&outNode, data1);

                if (l1->next == NULL)
                {
                    data1 = 101;
                }

                l1 = l1->next;
            }

            else if (data1 > data2)
            {
                InsertNode(&outNode, data2);

                if (l2->next == NULL)
                {
                    data2 = 101;
                }

                l2 = l2->next;
            }
        }
    }

    return outNode;
}
#endif

#if 0

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode head;
    struct ListNode* h = &head;

    if (l1 == NULL && l2 == NULL)
        return NULL;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            h->next = l1;
            l1 = l1->next;
            h = h->next;
        }
        else {
            h->next = l2;
            l2 = l2->next;
            h = h->next;
        }
    }

    if (l1) {
        h->next = l1;
    }
    if (l2) {
        h->next = l2;
    }

    return head.next;
}
#endif

//206. Reverse Linked List
#if 0
struct ListNode* reverseList(struct ListNode* head)
{
    if (head != NULL)
    {
        struct ListNode* tempNode = head;

        MyDynamicStack* myStack;

        MyDynamicStack_Create(&myStack, sizeof(int));

        while (head != NULL)
        {
            MyDynamicStack_Push(myStack, &head->val);

            head = head->next;
        }

        head = tempNode;

        while (!MyDynamicStack_Is_Empty(myStack))
        {
            MyDynamicStack_Pop(myStack, &tempNode->val);

            tempNode = tempNode->next;
        }

        return head;
    }
    else
    {
        return NULL;
    }
}
#endif

#if 0
//The idea is simple, just iterate all nodesand process reverse meanwhile.
struct ListNode* newHead = NULL;
while (head) {
    struct ListNode* tmpNode = head->next;
    head->next = newHead;
    newHead = head;
    head = tmpNode;
}
return newHead;
#endif
