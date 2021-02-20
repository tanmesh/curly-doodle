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
private:
    ListNode* findMiddle(ListNode* head) {
        ListNode* slowPtr = head;
        ListNode* fastPtr = head->next;

        while (fastPtr != NULL && fastPtr->next != NULL) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        return slowPtr;
    }

    ListNode* merge(ListNode* leftHalf, ListNode* rightHalf) {
        if (leftHalf == NULL) {
            return rightHalf;
        }
        if (rightHalf == NULL) {
            return leftHalf;
        }
        if (leftHalf->val < rightHalf->val) {
            ListNode* tmp = merge(leftHalf->next, rightHalf);
            leftHalf->next = tmp;
            return leftHalf;
        } else {
            ListNode* tmp = merge(leftHalf, rightHalf->next);
            rightHalf->next = tmp;
            return rightHalf;
        }
    }
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* middleNode = findMiddle(head);
        ListNode* rightHalfHead = middleNode->next;

        middleNode->next = NULL;

        ListNode* leftHalfList = sortList(head);
        ListNode* rightHalfList = sortList(rightHalfHead);

        return merge(leftHalfList, rightHalfList);
    }
};