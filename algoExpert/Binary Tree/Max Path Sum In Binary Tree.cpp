#include <vector>
using namespace std;

class BinaryTree {
public:
	int value;
	BinaryTree *left;
	BinaryTree *right;

	BinaryTree(int value);
	void insert(vector<int> values, int i = 0);
};

struct TreeInfo {
	int maxSumBranch;
	int maxPathSum;
};

TreeInfo findMaxPathSum(BinaryTree* tree) {
	if (tree == NULL) {
		return TreeInfo{0, INT_MIN};
	}

	TreeInfo leftTreePathSum = findMaxPathSum(tree->left);

	TreeInfo rightTreePathSum = findMaxPathSum(tree->right);

	int maxChildSumAsBranch = max(leftTreePathSum.maxSumBranch, rightTreePathSum.maxSumBranch);
	int maxSumBranch = max(maxChildSumAsBranch + tree->value, tree->value);
	int maxSumTree = max(maxSumBranch, leftTreePathSum.maxSumBranch + tree->value + rightTreePathSum.maxSumBranch);

	int runningMaxPathSum = max(maxSumTree, max(leftTreePathSum.maxPathSum, rightTreePathSum.maxPathSum));

	return TreeInfo{maxSumBranch, runningMaxPathSum};
}

int maxPathSum(BinaryTree tree) {
	TreeInfo maxPathSumResult = findMaxPathSum(&tree);
	return maxPathSumResult.maxPathSum;
}

