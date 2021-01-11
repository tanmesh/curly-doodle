// // Solution 1: Using Recursion
// using namespace std;

// // This is an input struct. Do not edit.
// class LinkedList {
// public:
//   int value;
//   LinkedList *next;

//   LinkedList(int value) {
//     this->value = value;
//     this->next = NULL;
//   }
// };

// struct LinkedListInfo {
// 	bool outerNodesAreEqual;
// 	LinkedList* leftNodeToCompare;
// };

// LinkedListInfo isPallindrome(LinkedList *leftNode, LinkedList *rightNode);

// bool linkedListPalindrome(LinkedList *head) {
// 	LinkedListInfo isPallindromeResult = isPallindrome(head, head);
// 	return isPallindromeResult.outerNodesAreEqual;
// }

// LinkedListInfo isPallindrome(LinkedList *leftNode, LinkedList *rightNode) {
// 	if(rightNode == NULL) {
// 		return LinkedListInfo{true, leftNode};
// 	}

// 	LinkedListInfo recursiveCallResult = isPallindrome(leftNode, rightNode->next);
// 	LinkedList *leftNodeToCompare = recursiveCallResult.leftNodeToCompare;
// 	bool outerNodesAreEqual = recursiveCallResult.outerNodesAreEqual;

// 	bool recursiveAreEqual = outerNodesAreEqual && (leftNodeToCompare->value == rightNode->value);
// 	LinkedList *nextLeftNodeToCompare = leftNodeToCompare->next;

// 	return LinkedListInfo{recursiveAreEqual, nextLeftNodeToCompare};
// }

// Solution 2 : Reversing the second half
using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
	int value;
	LinkedList *next;

	LinkedList(int value) {
		this->value = value;
		this->next = NULL;
	}
};

// T O(n), S O(1)
bool linkedListPalindrome(LinkedList *head) {
	// find middle
	LinkedList *slowPtr = head;
	LinkedList *fastPtr = head;
	while (fastPtr != NULL && fastPtr->next != NULL) {
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
	}

	// reverse the second half
	LinkedList *previousNode = slowPtr;
	LinkedList *currentNode = slowPtr->next;
	while (currentNode != NULL) {
		LinkedList *nextNode = currentNode->next;
		currentNode->next = previousNode;
		previousNode = currentNode;
		currentNode = nextNode;
	}

	// compare first and last elements
	LinkedList *leftPtr = head;
	LinkedList *rightPtr = previousNode;

	while (leftPtr != slowPtr) {
		if (leftPtr->value != rightPtr->value) {
			return false;
		}
		leftPtr = leftPtr->next;
		rightPtr = rightPtr->next;
	}
	return true;
}