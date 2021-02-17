using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
	int value;
	LinkedList *next = nullptr;

	LinkedList(int value) { this->value = value; }
};

// void addNode(LinkedList *resultNode, int value) {
// 	LinkedList *newNode = new LinkedList(value);
// 	resultNode->next = newNode;
// 	resultNode = resultNode->next;
// }

LinkedList *sumOfLinkedLists(LinkedList *linkedListOne,
                             LinkedList *linkedListTwo) {
	LinkedList *node1 = linkedListOne;
	LinkedList *node2 = linkedListTwo;

	LinkedList *resultHead = new LinkedList(0);
	LinkedList *resultNode = resultHead;

	int carry = 0;
	while (node1 != NULL && node2 != NULL) {
		int sum = node1->value + node2->value + carry;
		int value = sum % 10;
		carry = sum / 10;

		LinkedList *newNode = new LinkedList(value);
		resultNode->next = newNode;
		resultNode = resultNode->next;

		node1 = node1->next;
		node2 = node2->next;
	}

	while (node1 != NULL) {
		int sum = node1->value + carry;
		int value = sum % 10;
		carry = sum / 10;

		LinkedList *newNode = new LinkedList(value);
		resultNode->next = newNode;
		resultNode = resultNode->next;

		node1 = node1->next;
	}
	while (node2 != NULL) {
		int sum = node2->value + carry;
		int value = sum % 10;
		carry = sum / 10;

		LinkedList *newNode = new LinkedList(value);
		resultNode->next = newNode;
		resultNode = resultNode->next;

		node2 = node2->next;
	}

	if (carry != 0) {
		LinkedList *newNode = new LinkedList(carry);
		resultNode->next = newNode;
		resultNode = resultNode->next;
	}
	return resultHead->next;
}