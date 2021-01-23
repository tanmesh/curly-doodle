#include <vector>
using namespace std;

class BinaryTree {
public:
	int value;
	BinaryTree *left;
	BinaryTree *right;
	BinaryTree *parent;

	BinaryTree(int value, BinaryTree *parent = NULL);
	void insert(vector<int> values, int i = 0);
};

void iterativeInOrderTraversal(BinaryTree *tree, void (*callback)(BinaryTree *tree)) {
	BinaryTree *prevNode = NULL;
	BinaryTree *currNode = tree;

	while (currNode != NULL) {
		BinaryTree *nextNode;
		if (prevNode == NULL || prevNode == currNode->parent) {
			if (currNode->left != NULL) {
				nextNode = currNode->left;
			} else {
				(*callback)(currNode);
				nextNode = currNode->right != NULL ? currNode->right : currNode->parent;
			}
		} else if (prevNode == currNode->left) {
			(*callback)(currNode);
			nextNode = currNode->right != NULL ? currNode->right : currNode->parent;
		} else {
			nextNode = currNode->parent;
		}
		prevNode = currNode;
		currNode = nextNode;
	}
}

