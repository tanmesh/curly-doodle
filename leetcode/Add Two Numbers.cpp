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
	void addNode(ListNode **resultNode, int value) {
		ListNode *newNode = new ListNode(value);
		(*resultNode)->next = newNode;
		(*resultNode) = (*resultNode)->next;
	}
public:
	ListNode* addTwoNumbers(ListNode* linkedListOne, ListNode* linkedListTwo) {
		ListNode *node1 = linkedListOne;
		ListNode *node2 = linkedListTwo;

		ListNode *resultHead = new ListNode(0);
		ListNode *resultNode = resultHead;

		int carry = 0;
		while (node1 != NULL && node2 != NULL) {
			int sum = node1->val + node2->val + carry;
			int val = sum % 10;
			carry = sum / 10;

			addNode(&resultNode, val);

			node1 = node1->next;
			node2 = node2->next;
		}

		while (node1 != NULL) {
			int sum = node1->val + carry;
			int val = sum % 10;
			carry = sum / 10;

			addNode(&resultNode, val);

			node1 = node1->next;
		}
		while (node2 != NULL) {
			int sum = node2->val + carry;
			int val = sum % 10;
			carry = sum / 10;

			addNode(&resultNode, val);

			node2 = node2->next;
		}

		if (carry != 0) {
			addNode(&resultNode, carry);
		}
		return resultHead->next;
	}
};