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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;

        // no element
        if (current == NULL) {
            return current;
        }

        // one element
        ListNode* prev = current;
        current = current->next;
        if (current == NULL) {
            return head;
        }

        // more than one element
        while (current != NULL) {
            if (prev->val == current->val) {
                prev->next = current->next;
                current->next = NULL;
                current = prev;
            }

            prev = current;
            current = current->next;
        }

        return head;
    }
};