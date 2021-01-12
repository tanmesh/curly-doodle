// Solution 1: Mutating one Linked List
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
    ListNode* mergeTwoLists(ListNode* headOne, ListNode* headTwo) {
        if (headOne == NULL && headTwo == NULL) {
            return NULL;
        } else if (headOne == NULL && headTwo != NULL) {
            return headTwo;
        } else if (headOne != NULL && headTwo == NULL) {
            return headOne;
        }

        ListNode* previousNodeOne = NULL;
        ListNode* currentNodeOne = headOne;
        ListNode* currentNodeTwo = headTwo;

        while (currentNodeOne != NULL && currentNodeTwo != NULL) {
            ListNode* nextNodeOne = currentNodeOne->next;
            ListNode* nextNodeTwo = currentNodeTwo->next;

            if (currentNodeOne->val <= currentNodeTwo->val) {
                previousNodeOne = currentNodeOne;
                currentNodeOne = currentNodeOne->next;
            } else {
                if (previousNodeOne != NULL) {
                    previousNodeOne->next = currentNodeTwo;
                }
                previousNodeOne = currentNodeTwo;
                currentNodeTwo = nextNodeTwo;
                previousNodeOne->next = currentNodeOne;
            }
        }

        if (currentNodeOne == NULL) {
            previousNodeOne->next = currentNodeTwo;
        }

        return headOne->val <= headTwo->val ? headOne : headTwo;
    }
};