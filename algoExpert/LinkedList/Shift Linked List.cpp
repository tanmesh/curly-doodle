using namespace std;

class LinkedList {
public:
	int value;
	LinkedList *next;

	LinkedList(int value) {
		this->value = value;
		next = NULL;
	}
};

LinkedList *shiftLinkedList(LinkedList *head, int k) {
	int listLength = 1;
	LinkedList *tail = head;
	while (tail->next != NULL) {
		++listLength;
		tail = tail->next;
	}

	int offset = abs(k) % listLength;
	if (offset == 0) {
		return head;
	}

	int newTailPos = k > 0 ? listLength - offset : offset;

	LinkedList *newTail = head;
	int tmpNewTailPos = newTailPos;
	while (tmpNewTailPos != 1) {
		newTail = newTail->next;
		--tmpNewTailPos;
	}

	LinkedList *newHead = newTail->next;
	newTail->next = NULL;
	tail->next = head;
	return newHead;
}