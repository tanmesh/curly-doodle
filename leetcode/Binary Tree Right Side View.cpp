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
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) { return {}; }
        vector<int> ans;

        queue<TreeNode*> q;
        q.push(root);

        ans.push_back(root->val);
        while (!q.empty()) {
            int lastValue = -1;

            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* currNode = q.front();
                q.pop();

                if (currNode->left != NULL) {
                    q.push(currNode->left);
                    lastValue = currNode->left->val;
                }
                if (currNode->right != NULL) {
                    q.push(currNode->right);
                    lastValue = currNode->right->val;
                }
            }
            if (lastValue != -1) { ans.push_back(lastValue); }
        }

        return ans;
    }
};