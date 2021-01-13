/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int listLength = 1;
        ListNode* tail = head;
        while (tail->next != NULL) {
            ++listLength;
            tail = tail->next;
        }

        int offset1 = k;
        int offset2 = listLength - k + 1;

        ListNode* ptr1 = head;
        ListNode* ptr2 = head;

        for (int i = 1; i < offset1; ++i) {
            ptr1 = ptr1->next;
        }

        for (int i = 1; i < offset2; ++i) {
            ptr2 = ptr2->next;
        }

        int tmp = ptr1->val;
        ptr1->val = ptr2->val;
        ptr2->val = tmp;

        return head;
    }
};