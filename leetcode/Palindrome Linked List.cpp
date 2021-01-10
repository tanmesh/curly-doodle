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
    struct LinkedListInfo {
        bool outerNodesAreEqual;
        ListNode* leftNodeToCompare;
    };

    LinkedListInfo checkForPallindrome(ListNode *leftNode, ListNode *rightNode) {
        // Base Condition
        if (rightNode == NULL) {
            return LinkedListInfo{true, leftNode};
        }

        LinkedListInfo recursiveCallResult = checkForPallindrome(leftNode, rightNode->next);
        bool outerNodesAreEqual = recursiveCallResult.outerNodesAreEqual;
        ListNode *leftNodeToCompare = recursiveCallResult.leftNodeToCompare;

        // Check: "Pallindrom till now?" and "current left and right nodes are equal?"
        bool recursiveAreEqual = outerNodesAreEqual && (leftNodeToCompare->val == rightNode->val);

        // move left node right
        ListNode *nextLeftNodeToCompare = leftNodeToCompare->next;

        return LinkedListInfo{recursiveAreEqual, nextLeftNodeToCompare};
    }

    bool isPalindrome(ListNode* head) {
        LinkedListInfo resultFromRecursion = checkForPallindrome(head, head);
        return resultFromRecursion.outerNodesAreEqual;
    }
};