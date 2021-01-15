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
        ListNode* resultantHead;
        int carry;
    };

    int calculateLength(ListNode* head) {
        int length = 0;
        ListNode* tmp = head;
        while (tmp != NULL) {
            ++length;
            tmp = tmp->next;
        }
        return length;
    }

    ListNode* makeNode(int val) {
        ListNode* node = new ListNode();
        node->val = val;
        node->next = NULL;
        return node;
    }

    void makeEqualLengthLinkedList(ListNode* l1, ListNode* l2) {
        int l1Length = calculateLength(l1), l2Length = calculateLength(l2);
        int lengthDiff = abs(l1Length - l2Length);

        if (l1Length > l2Length) {
            while (lengthDiff != 0) {
                ListNode* tmpNode = makeNode(0);
                tmpNode->next = l2;
                l2 = tmpNode;
                --lengthDiff;
            }
        } else if (l1Length < l2Length) {
            while (lengthDiff != 0) {
                ListNode* tmpNode = makeNode(0);
                tmpNode->next = l1;
                l1 = tmpNode;
                --lengthDiff;
            }
        }
    }

    LinkedListInfo addTwoNumberRecursive(ListNode* pointer1, ListNode* pointer2) {
        if (pointer1 == NULL && pointer2 == NULL) {
            return LinkedListInfo{NULL, 0};
        }
        LinkedListInfo recursiveCallResult = addTwoNumberRecursive(pointer1->next, pointer2->next);
        ListNode* resultantHead = recursiveCallResult.resultantHead;
        int carry = recursiveCallResult.carry;

        int sum = pointer1->val + pointer2->val;
        sum += carry;

        ListNode* tmpNode = makeNode(sum % 10);
        tmpNode->next = resultantHead;
        resultantHead = tmpNode;

        carry = sum / 10;
        return LinkedListInfo{resultantHead, carry};
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // makeEqualLengthLinkedList(l1, l2);
        int l1Length = calculateLength(l1), l2Length = calculateLength(l2);
        int lengthDiff = abs(l1Length - l2Length);

        if (l1Length > l2Length) {
            while (lengthDiff != 0) {
                ListNode* tmpNode = makeNode(0);
                tmpNode->next = l2;
                l2 = tmpNode;
                --lengthDiff;
            }
        } else if (l1Length < l2Length) {
            while (lengthDiff != 0) {
                ListNode* tmpNode = makeNode(0);
                tmpNode->next = l1;
                l1 = tmpNode;
                --lengthDiff;
            }
        }

        ListNode* resultantHead;
        LinkedListInfo recursiveCallResult = addTwoNumberRecursive(l1, l2);
        int carry = recursiveCallResult.carry;

        if (carry == 0) {
            return recursiveCallResult.resultantHead;
        }
        ListNode* tmpNode = makeNode(carry);
        tmpNode->next = recursiveCallResult.resultantHead;
        recursiveCallResult.resultantHead = tmpNode;
        return recursiveCallResult.resultantHead;
    }
};