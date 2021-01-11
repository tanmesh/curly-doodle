/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }
        ListNode *slowPtr = head->next;
        ListNode *fastPtr = head->next->next;

        while (fastPtr != NULL && fastPtr->next != NULL && slowPtr != fastPtr) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        if (slowPtr == fastPtr) {
            return true;
        }
        return false;
    }
};