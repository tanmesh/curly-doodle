// // My solution
// using namespace std;

// class LinkedList {
// public:
//   int value;
//   LinkedList *next;

//   LinkedList(int value) {
//     this->value = value;
//     this->next = NULL;
//   }
// };

// LinkedList *reverseLinkedList(LinkedList *head) {
//   LinkedList *T1 = NULL;
// 	LinkedList *T2 = head;
// 	LinkedList *T3 = head->next;

// 	while(T3 != NULL) {
// 		T2->next = T1;
// 		T1 = T2;
// 		T2 = T3;
// 		T3 = T3->next;
// 	}

// 	T2->next = T1;

//   return T2;
// }

// Clean Solution
using namespace std;

class LinkedList {
public:
	int value;
	LinkedList *next;

	LinkedList(int value) {
		this->value = value;
		this->next = NULL;
	}
};

// Time O(n), Space O(1)
LinkedList *reverseLinkedList(LinkedList *head) {
	LinkedList *previousNode = NULL;
	LinkedList *currentNode = head;

	while (currentNode != NULL) {
		LinkedList *nextNode = currentNode->next;
		currentNode->next = previousNode;
		previousNode = currentNode;
		currentNode = nextNode;
	}

	return previousNode;
}