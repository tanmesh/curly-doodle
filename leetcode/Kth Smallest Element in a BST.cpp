// Solution 1: using recursive Inorder Traversal, O(#nodes)T, O(#nodes)S
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
    void calculateInorderTraversal(TreeNode* root, vector<int>& inorderTraversal) {
        if (root == NULL) {
            return;
        }

        calculateInorderTraversal(root->left, inorderTraversal);
        inorderTraversal.push_back(root->val);
        calculateInorderTraversal(root->right, inorderTraversal);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorderTraversal;
        calculateInorderTraversal(root, inorderTraversal);
        return inorderTraversal[k - 1];
    }
};