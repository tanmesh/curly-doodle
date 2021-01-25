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

    ListNode* reverseBetween(ListNode* head, int m) {
        if (head == NULL || head->next == NULL || m <= 1) {
            return head;
        }

        // there is atleat 2 nodes
        ListNode* prevNode = NULL;
        ListNode* nextNode = NULL;
        ListNode* currNode = head;


        while (currNode != NULL && m > 0) {
            nextNode = currNode->next;

            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;

            m--;
        }

        // cout << head->val << endl;
        head->next = nextNode;

        return prevNode;
    }

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prevNode = dummy;
        ListNode* currNode = head;

        int tmpM = m;
        while (tmpM > 1) {
            prevNode = currNode;
            currNode = currNode->next;
            tmpM--;
        }

        ListNode* receivedHead = reverseBetween(currNode, n - m + 1);

        prevNode->next = receivedHead;

        return dummy->next;

    }
};