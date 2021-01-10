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
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        int len = 0;
        ListNode* tmp = head;

        // calculate list length and store in "len"
        while (tmp != NULL) {
            ++len;
            tmp = tmp -> next;
        }

        // traverse from front
        k = len - k;

        if (k == 0) {
            head = head -> next;
            return head;
        }

        tmp = head;
        ListNode *prev = tmp;
        while (tmp != NULL && k > 0) {
            --k;
            prev = tmp;
            tmp = tmp -> next;
        }
        prev -> next = tmp -> next;
        return head;
    }
};