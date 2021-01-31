/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

bool cmp(pair<int, int> &a, pair<int, int> &b) {
	if (a.first < b.first || a.first == b.first && a.second < b.second) {
		return true;
	}
	return false;
}

class Solution {
public:
	vector<vector<int>> verticalTraversal(TreeNode* root) {
		if (root == NULL) {
			return {};
		}

		unordered_map<int, vector<pair<int, int>>> columnTable; // {col, [{level, val}]}
		queue<pair<TreeNode*, pair<int, int>>> queue;           // {Node, {level, col}}

		queue.push({root, {0, 0}});

		while (!queue.empty()) {
			pair<TreeNode*, pair<int, int>> p = queue.front();
			queue.pop();

			TreeNode* currentNode = p.first;
			int level = p.second.first;
			int column = p.second.second;

			if (currentNode != NULL) {
				if (columnTable.find(column) == columnTable.end()) {
					columnTable[column] = vector<pair<int, int>> {{level, currentNode->val}};
				} else {
					columnTable[column].push_back({level, currentNode->val});
				}

				queue.push({currentNode->left, {level + 1, column - 1}});
				queue.push({currentNode->right, {level + 1, column + 1}});
			}
		}

		vector<pair<int, vector<pair<int, int>>>> elems(columnTable.begin(), columnTable.end());
		sort(elems.begin(), elems.end());

		vector<vector<int>> output;
		for (auto it : elems) {
			vector<int> tmp;
			sort((it.second).begin(), (it.second).end(), cmp);
			for (auto itt : it.second) {
				tmp.push_back(itt.second);
			}
			output.push_back(tmp);
		}

		return output;
	}
};