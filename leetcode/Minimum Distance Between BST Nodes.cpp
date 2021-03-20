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
    int prevValue;
    int ans;
    
    void dfs(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        dfs(root->left);
        
        if(prevValue != INT_MAX) {
            ans = min(ans, root->val - prevValue);
        }
        prevValue = root->val;
        
        dfs(root->right);
    }
    
public:
    int minDiffInBST(TreeNode* root) {
        prevValue = INT_MAX;
        ans = INT_MAX;
        
        
        dfs(root);
        return ans;
    }
};