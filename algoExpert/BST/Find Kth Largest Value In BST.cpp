using namespace std;

// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};

void dfs(BST* node, vector<int> &sortedList) {
	if(node == NULL) {
		return;
	}
	dfs(node->left, sortedList);
	sortedList.push_back(node->value);
	dfs(node->right, sortedList);
}
	
int findKthLargestValueInBst(BST *tree, int k) {
	vector<int> sortedList;
	dfs(tree, sortedList);
	int i = sortedList.size() - k;
	return sortedList[i];
}
