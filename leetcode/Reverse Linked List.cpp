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
        LinkedList* leftNodeToCompare;
    };

    LinkedListInfo getReverseList(ListNode* leftNode, ListNode* rightNode) {

    }

    ListNode* reverseList(ListNode* head) {
        head = getReverseList(head, head);
        return head;
    }
};