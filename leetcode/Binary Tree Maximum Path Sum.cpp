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
struct TreeInfo {
    int maxSumBranch;
    int maxPathSum;  
};

class Solution {
    TreeInfo findMaxPathSum(TreeNode* root) {
        if(root == NULL) {
            return TreeInfo{0, INT_MIN};
        }
        TreeInfo leftBranch = findMaxPathSum(root->left);
        TreeInfo rightBranch = findMaxPathSum(root->right);
        
        /*
        "need to find the maxSumBranch and maxPathSum"
        
        maxSumBranch:
            1. pick from the either branches.
            2. decide whether u want to continue the branch by adding the current root or want to start a fresh branch with the      current root
        
        maxPathSum:
            1. decide either the branch is big or the tree
            2. also, decide whether adding the current root is making the branch/ tree small or not?
        */
        int maxChildSumBranch = max(leftBranch.maxSumBranch, rightBranch.maxSumBranch);
        int maxSumBranch = max(maxChildSumBranch + root->val, root->val);
        
        int maxSumTree = max(maxSumBranch, leftBranch.maxSumBranch + root->val + rightBranch.maxSumBranch);
        int runningMaxPathSum = max(maxSumTree, max(leftBranch.maxPathSum, rightBranch.maxPathSum));
        
        return TreeInfo{maxSumBranch, runningMaxPathSum};
    }
    
public:
    int maxPathSum(TreeNode* root) {
        TreeInfo maxPathSumResult = findMaxPathSum(root);
        return maxPathSumResult.maxPathSum;
    }
};