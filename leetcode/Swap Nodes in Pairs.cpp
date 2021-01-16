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
    ListNode* swapPairs(ListNode* head) {
        ListNode* current = head;
        if (current == NULL || current->next == NULL) {
            return head;
        }
        while (current != NULL && current->next != NULL) {
            ListNode* currentNext = current->next;

            int tmp = current->val;
            current->val = currentNext->val;
            currentNext->val = tmp;

            if (current->next->next == NULL) {
                break;
            } else {
                current = current->next->next;
            }
        }
        return head;
    }
};