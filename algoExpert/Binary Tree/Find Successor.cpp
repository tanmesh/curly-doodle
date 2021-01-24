// Solution 1: O(height)T, O(1)S
using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
	int value;
	BinaryTree *left = nullptr;
	BinaryTree *right = nullptr;
	BinaryTree *parent = nullptr;

	BinaryTree(int value) { this->value = value; }
};

BinaryTree *leftMostChild(BinaryTree *currentNode) {
	while (currentNode->left != NULL) {
		currentNode = currentNode->left;
	}
	return currentNode;
}

BinaryTree *rightMostParent(BinaryTree *currentNode) {
	while (currentNode->parent != NULL && currentNode->parent->right == currentNode) {
		currentNode = currentNode->parent;
	}
	return currentNode->parent;
}

BinaryTree *findSuccessor(BinaryTree *tree, BinaryTree *node) {
	if (node->right != NULL) {
		return leftMostChild(node->right);
	}
	return rightMostParent(node);
}


// // Solution 2: Storing the traversal in list and finding from it, O(N)T, O(N)S
// using namespace std;

// // This is an input class. Do not edit.
// class BinaryTree {
// public:
// 	int value;
// 	BinaryTree *left = nullptr;
// 	BinaryTree *right = nullptr;
// 	BinaryTree *parent = nullptr;

// 	BinaryTree(int value) { this->value = value; }
// };

// void inorder(BinaryTree *currentNode, vector<BinaryTree *>& inorderList) {
// 	if (currentNode == NULL)	{
// 		return;
// 	}
// 	inorder(currentNode->left, inorderList);
// 	inorderList.push_back(currentNode);
// 	inorder(currentNode->right, inorderList);
// }

// BinaryTree *findSuccessor(BinaryTree *tree, BinaryTree *node) {
// 	vector<BinaryTree *> inorderList;
// 	inorder(tree, inorderList);

// 	BinaryTree * itPrev = nullptr;
// 	for (auto it : inorderList) {
// 		if (itPrev == node) {
// 			return it;
// 		}
// 		itPrev = it;
// 	}

// 	return nullptr;
// }

