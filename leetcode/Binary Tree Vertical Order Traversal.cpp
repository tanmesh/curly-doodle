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
class Solution {
public:
    bool comp(pair<int, vector<int>> &a, pair<int, vector<int>> &b) {
        return (a.first < b.first);
    }

    vector< vector<int> > verticalOrder(TreeNode* root) {
        if (root == NULL) {
            return {};
        }

        unordered_map<int, vector<int>> columnTable;
        queue<pair<TreeNode*, int>> queue;

        int column = 0;

        queue.push({root, column});

        while (!queue.empty()) {
            pair<TreeNode*, int> p = queue.front();
            queue.pop();

            TreeNode* currentNode = p.first;
            column = p.second;

            if (currentNode != NULL) {
                if (columnTable.find(column) == columnTable.end()) {
                    columnTable[column] = vector<int> {currentNode->val};
                } else {
                    columnTable[column].push_back(currentNode->val);
                }

                queue.push({currentNode->left, column - 1});
                queue.push({currentNode->right, column + 1});
            }
        }

        vector<pair<int, vector<int>>> elems(columnTable.begin(), columnTable.end());
        sort(elems.begin(), elems.end());

        vector<vector<int> > output;

        for (auto it : elems) {
            output.push_back(it.second);
        }

        return output;
    }
};