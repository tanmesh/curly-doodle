class BST {
public:
	int value;
	BST *left;
	BST *right;

	BST(int val);
	BST &insert(int val);
};

int findClosestValueInBst(BST *tree, int target) {
	BST *possibleAns = tree;
	int minDiff = abs(tree->value - target);

	while (tree != NULL) {
		int diff = abs(tree->value - target);

		if (diff < minDiff) {
			minDiff = diff;
			possibleAns = tree;
		}

		if (tree->value < target) {
			tree = tree->right;
		} else {
			tree = tree->left;
		}
	}

	return possibleAns->value;
}

