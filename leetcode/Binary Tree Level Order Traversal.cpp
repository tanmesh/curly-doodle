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

    void findTraverseOrderUsingRec(TreeNode* root, vector<vector<int>>& traversalOrder, int currentLevel) {
        if (root == NULL) {
            return;
        }

        if (traversalOrder.size() == currentLevel) {
            vector<int> newLevel;
            newLevel.push_back(root->val);
            traversalOrder.push_back(newLevel);
        } else {
            traversalOrder[currentLevel].push_back(root->val);
        }

        findTraverseOrderUsingRec(root->left, traversalOrder, currentLevel + 1);

        findTraverseOrderUsingRec(root->right, traversalOrder, currentLevel + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> traversalOrder;
        int level = 0;
        findTraverseOrderUsingRec(root, traversalOrder, level);

        return traversalOrder;
    }
};