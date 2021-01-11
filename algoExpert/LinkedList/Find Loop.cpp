#include <vector>
using namespace std;

class LinkedList {
public:
	int value;
	LinkedList *next;

	LinkedList(int value);
};

LinkedList *findLoop(LinkedList *head) {
	LinkedList *slowPtr = head->next;
	LinkedList *fastPtr = head->next->next;

	while (slowPtr != fastPtr) {
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
	}

	slowPtr = head;
	while (slowPtr != fastPtr) {
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next;
	}

	return slowPtr;
}

