/**
 * @class Solution
 * @brief Provides a method to merge two sorted linked lists.
 *
 * The Solution class contains a method to merge two sorted singly-linked lists
 * into a single sorted linked list.
 */

/**
 * @brief Merges two sorted linked lists into one sorted list.
 *
 * This function takes two pointers to the heads of two sorted singly-linked lists,
 * and merges them into a single sorted linked list. The merged list is constructed
 * by iteratively selecting the node with the smaller value from the heads of the two lists.
 * The function returns a pointer to the head of the merged linked list.
 *
 * @param list1 Pointer to the head of the first sorted linked list.
 * @param list2 Pointer to the head of the second sorted linked list.
 * @return ListNode* Pointer to the head of the merged sorted linked list.
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode dummy;
        ListNode *tail = &dummy;

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if (list1 != nullptr)
            tail->next = list1;
        else
            tail->next = list2;

        return dummy.next;
    }
};