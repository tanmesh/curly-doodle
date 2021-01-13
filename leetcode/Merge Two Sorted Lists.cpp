// Solution 1: Recursion
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
	void mergeTwoLinkedList(ListNode* p1, ListNode* p1Prev, ListNode* p2) {
		if (p1 == NULL) {
			p1Prev->next = p2;
			return;
		} else if (p2 == NULL) {
			return;
		} else if (p1->val < p2->val) {
			mergeTwoLinkedList(p1->next, p1, p2);
		} else {
			if (p1Prev != NULL) {
				p1Prev->next = p2;
			}
			p1Prev = p2;
			p2 = p2->next;
			p1Prev->next = p1;
			mergeTwoLinkedList(p1, p1Prev, p2);
		}
	}

	ListNode* mergeTwoLists(ListNode* headOne, ListNode* headTwo) {
		if (headOne == NULL && headTwo == NULL) {
			return NULL;
		} else if (headOne != NULL && headTwo == NULL) {
			return headOne;
		} else if (headOne == NULL && headTwo != NULL) {
			return headTwo;
		}
		ListNode* previousOne = NULL;
		mergeTwoLinkedList(headOne, previousOne, headTwo);
		return headOne->val < headTwo->val ? headOne : headTwo;
	}
};

// // Solution 2: Mutating one Linked List
// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* headOne, ListNode* headTwo) {
//         if(headOne == NULL && headTwo == NULL) {
//           return NULL;
//         } else if(headOne == NULL && headTwo != NULL) {
//             return headTwo;
//         } else if(headOne != NULL && headTwo == NULL) {
//             return headOne;
//         }

//         ListNode* previousNodeOne = NULL;
//         ListNode* currentNodeOne = headOne;
//         ListNode* currentNodeTwo = headTwo;

//         // T O(n+m), S O(1)
//         while(currentNodeOne != NULL && currentNodeTwo != NULL) {
//             ListNode* nextNodeOne = currentNodeOne->next;
//             ListNode* nextNodeTwo = currentNodeTwo->next;

//             if(currentNodeOne->val <= currentNodeTwo->val) {
//                 previousNodeOne = currentNodeOne;
//                 currentNodeOne = currentNodeOne->next;
//             } else {
//                     if(previousNodeOne != NULL) {
//                         previousNodeOne->next = currentNodeTwo;
//                     }
//                 previousNodeOne = currentNodeTwo;
//                 currentNodeTwo = nextNodeTwo;
//                 previousNodeOne->next = currentNodeOne;
//             }
//         }

//         if(currentNodeOne == NULL) {
//             previousNodeOne->next = currentNodeTwo;
//         }

//         return headOne->val <= headTwo->val ? headOne : headTwo;
//     }
// };