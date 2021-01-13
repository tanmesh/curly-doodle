// Solution 1: Recursion
#include <vector>

using namespace std;

// This is an input class. Do not edit.
class LinkedList {
public:
    int value;
    LinkedList *next;

    LinkedList(int value) {
        this->value = value;
        next = NULL;
    }
};

// T O(n+m), S O(n+m)
void mergeTwoLinkedList(LinkedList* p1, LinkedList* p1Prev, LinkedList* p2) {
    if (p1 == NULL) {
        p1Prev->next = p2;
        return;
    } else if (p2 == NULL) {
        return;
    } else if (p1->value < p2->value) {
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

LinkedList *mergeLinkedLists(LinkedList *headOne, LinkedList *headTwo) {
    LinkedList* previousOne = NULL;
    mergeTwoLinkedList(headOne, previousOne, headTwo);
    return headOne->value < headTwo->value ? headOne : headTwo;
}
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
//         if (headOne == NULL && headTwo == NULL) {
//             return NULL;
//         } else if (headOne == NULL && headTwo != NULL) {
//             return headTwo;
//         } else if (headOne != NULL && headTwo == NULL) {
//             return headOne;
//         }

//         ListNode* previousNodeOne = NULL;
//         ListNode* currentNodeOne = headOne;
//         ListNode* currentNodeTwo = headTwo;

//         while (currentNodeOne != NULL && currentNodeTwo != NULL) {
//             ListNode* nextNodeOne = currentNodeOne->next;
//             ListNode* nextNodeTwo = currentNodeTwo->next;

//             if (currentNodeOne->val <= currentNodeTwo->val) {
//                 previousNodeOne = currentNodeOne;
//                 currentNodeOne = currentNodeOne->next;
//             } else {
//                 if (previousNodeOne != NULL) {
//                     previousNodeOne->next = currentNodeTwo;
//                 }
//                 previousNodeOne = currentNodeTwo;
//                 currentNodeTwo = nextNodeTwo;
//                 previousNodeOne->next = currentNodeOne;
//             }
//         }

//         if (currentNodeOne == NULL) {
//             previousNodeOne->next = currentNodeTwo;
//         }

//         return headOne->val <= headTwo->val ? headOne : headTwo;
//     }
// };