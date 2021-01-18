using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree {
public:
	int value;
	BinaryTree *left;
	BinaryTree *right;

	BinaryTree(int value) {
		this->value = value;
		left = NULL;
		right = NULL;
	}
};

void findBranchSumRecursive(BinaryTree *node, int sumTillNow, vector<int> &branchSum) {
	if (node->left == NULL && node->right == NULL) {
		sumTillNow += node->value;
		branchSum.push_back(sumTillNow);
		return;
	}

	if (node->left != NULL) {
		findBranchSumRecursive(node->left, sumTillNow + node->value, branchSum);
	}

	if (node->right != NULL) {
		findBranchSumRecursive(node->right, sumTillNow + node->value, branchSum);
	}
}

vector<int> branchSums(BinaryTree *root) {
	vector<int> branchSum;
	findBranchSumRecursive(root, 0, branchSum);
	return branchSum;
}

