class BST {
public:
	int value;
	BST *left;
	BST *right;

	BST(int val);
	BST &insert(int val);
};

bool validateBst(BST *currNode, int minBound, int maxBound) {
	if (currNode->value < minBound || currNode->value >= maxBound) {
		return false;
	}

	if (currNode->left != NULL && !validateBst(currNode->left, minBound, currNode->value)) {
		return false;
	}

	if (currNode->right != NULL && !validateBst(currNode->right, currNode->value, maxBound)) {
		return false;
	}

	return true;
}

bool validateBst(BST *tree) {
	return validateBst(tree, INT_MIN, INT_MAX);
}

