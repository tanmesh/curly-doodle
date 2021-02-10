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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        vector<vector<int>> ans;

        int rev = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            vector<int> tmp;
            for (int i = 0; i < size; ++i) {
                TreeNode* currNode = q.front();
                q.pop();

                tmp.push_back(currNode->val);
                if (currNode->left != NULL) { q.push(currNode->left); }
                if (currNode->right != NULL) { q.push(currNode->right); }
            }

            if (rev % 2 == 0) {
                ans.push_back(tmp);
            } else {
                vector<int> newTmp;
                for (int i = tmp.size() - 1; i >= 0; --i) {
                    newTmp.push_back(tmp[i]);
                }
                ans.push_back(newTmp);
            }
            rev = (rev + 1) % 2;
        }

        return ans;
    }
};