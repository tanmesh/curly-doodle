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
	LinkedList *first = head;
	LinkedList *second = head;
	int cnt = k;

	// move second ptr K nodes ahead
	while (second != NULL && cnt > 0) {
		second = second -> next;
		--cnt;
	}

	if (second == NULL) {
		head -> value = head -> next -> value;
		head -> next = head -> next -> next;
		return;
	}

	// move both first and second ptr till NULL
	while (second->next != NULL) {
		second = second -> next;
		first = first -> next;
	}
	first -> next = first -> next -> next;
}

