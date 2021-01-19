using namespace std;

// This is an input class. Do not edit.
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

struct TreeInfo {
	int diameter;
	int height;
};

TreeInfo getTreeInfo(BinaryTree* tree) {
	if (tree == NULL) {
		return TreeInfo{0, 0};
	}

	TreeInfo leftTreeInfo = getTreeInfo(tree->left);
	TreeInfo rightTreeInfo = getTreeInfo(tree->right);

	int longestPathThroughRoot = leftTreeInfo.height + rightTreeInfo.height;
	int maxDiameterSoFar = max(leftTreeInfo.diameter, rightTreeInfo.diameter);
	int currentDiameter = max(longestPathThroughRoot, maxDiameterSoFar);
	int currentHeight = 1 + max(leftTreeInfo.height, rightTreeInfo.height);

	return TreeInfo{currentDiameter, currentHeight};
}

int binaryTreeDiameter(BinaryTree *tree) {
	return getTreeInfo(tree).diameter;
}