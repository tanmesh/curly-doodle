using namespace std;

class Node {
public:
	int value;
	Node *prev;
	Node *next;

	Node(int value);
};

// Feel free to add new properties and methods to the class.
class DoublyLinkedList {
public:
	Node *head;
	Node *tail;

	DoublyLinkedList() {
		head = NULL;
		tail = NULL;
	}

	void setHead(Node *node) {
		if (head == NULL) {
			head = node;
			tail = node;
			return;
		}
		insertBefore(head, node);
	}

	void setTail(Node *node) {
		if (tail == NULL) {
			setHead(node);
			return;
		}
		insertAfter(tail, node);
	}

	void insertBefore(Node *node, Node *nodeToInsert) {
		remove(nodeToInsert);

		nodeToInsert->prev = node->prev;
		nodeToInsert->next = node;
		if (node->prev == NULL) {
			head = nodeToInsert;
		} else {
			node->prev->next = nodeToInsert;
		}
		node->prev = nodeToInsert;
	}

	void insertAfter(Node *node, Node *nodeToInsert) {
		remove(nodeToInsert);

		nodeToInsert->prev = node;
		nodeToInsert->next = node->next;
		if (node->next == NULL) {
			tail = nodeToInsert;
		} else {
			node->next->prev = nodeToInsert;
		}
		node->next = nodeToInsert;
	}

	void insertAtPosition(int position, Node *nodeToInsert) {
		if (position == 1) {
			setHead(nodeToInsert);
			return;
		}
		Node* currentNode = head;
		int currentPos = position;
		while (currentNode != NULL && currentPos != 1) {
			--currentPos;
			currentNode = currentNode->next;
		}
		if (currentNode != NULL) {
			insertBefore(currentNode, nodeToInsert);
		} else {
			setTail(nodeToInsert);
		}
	}

	void removeNodesWithValue(int value) {
		Node *currentNode = head;
		while (currentNode != NULL) {
			Node* nodeToRemove = currentNode;
			currentNode = currentNode->next;
			if (nodeToRemove->value == value) {
				remove(nodeToRemove);
			}
		}
	}

	void remove(Node *node) {
		if (head == node) {
			head = head->next;
		}
		if (tail == node) {
			tail = tail->prev;
		}
		removeNodeBindings(node);
	}

	void removeNodeBindings(Node* node) {
		if (node->next != NULL) {
			node->next->prev = node->prev;
		}
		if (node->prev != NULL) {
			node->prev->next = node->next;
		}
		node->next = NULL;
		node->prev = NULL;
	}

	bool containsNodeWithValue(int value) {
		Node *currentNode = head;
		while (currentNode != NULL) {
			if (currentNode->value == value) {
				return true;
			}
			currentNode = currentNode->next;
		}
		return false;
	}
};

