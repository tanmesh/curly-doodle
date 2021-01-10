#include <vector>
using namespace std;

class LinkedList {
public:
	int value;
	LinkedList *next;

	LinkedList(int value);
	void addMany(vector<int> values);
	vector<int> getNodesInArray();
};

void removeKthNodeFromEnd(LinkedList *head, int k) {
	int len = 0;
	LinkedList* tmp = head;

	// calculate list length and store in "len"
	while (tmp != NULL) {
		++len;
		tmp = tmp -> next;
	}

	// traverse from front
	k = len - k;

	if (k == 0) {
		head -> value = head -> next -> value;
		head -> next = head -> next -> next;
		return;
	}

	tmp = head;
	while (tmp -> next != NULL && k > 1) {
		--k;
		tmp = tmp -> next;
	}
	tmp -> next = tmp -> next -> next;
}

