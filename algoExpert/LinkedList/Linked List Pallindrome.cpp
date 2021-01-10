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

struct LinkedListInfo {
	bool outerNodesAreEqual;
	LinkedList* leftNodeToCompare;
};

LinkedListInfo isPallindrome(LinkedList *leftNode, LinkedList *rightNode);

bool linkedListPalindrome(LinkedList *head) {
	LinkedListInfo isPallindromeResult = isPallindrome(head, head);
	return isPallindromeResult.outerNodesAreEqual;
}

LinkedListInfo isPallindrome(LinkedList *leftNode, LinkedList *rightNode) {
	if(rightNode == NULL) {
		return LinkedListInfo{true, leftNode};
	}
	
	LinkedListInfo recursiveCallResult = isPallindrome(leftNode, rightNode->next);
	LinkedList *leftNodeToCompare = recursiveCallResult.leftNodeToCompare;
	bool outerNodesAreEqual = recursiveCallResult.outerNodesAreEqual;
	
	bool recursiveAreEqual = outerNodesAreEqual && (leftNodeToCompare->value == rightNode->value);
	LinkedList *nextLeftNodeToCompare = leftNodeToCompare->next;
	
	return LinkedListInfo{recursiveAreEqual, nextLeftNodeToCompare};
}

