// Solution 2: O(logN)T, O(1)S
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* currNode = root;
        TreeNode* answerNode = NULL;
        
        while(currNode != NULL) {
            if(currNode->val > p->val) {
                answerNode = currNode;
                currNode = currNode->left;
            } else {
                currNode = currNode->right;
            }
        }
        
        return answerNode;
    }
};
// // Solution 1: O(V+E)T, O(V)S
// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
// class Solution {
//     void dfs(TreeNode* root, vector<TreeNode*> &inorder) {
//         if(root == NULL) {
//             return;
//         }
//         dfs(root->left, inorder);
//         inorder.push_back(root);
//         dfs(root->right, inorder);
//     }
// public:
//     TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
//         vector<TreeNode*> inorder;
        
//         dfs(root, inorder);
        
//         TreeNode* prevNode = NULL;
//         for(auto it: inorder) {
//             if(prevNode == p) {
//                 return it;
//             }
//             prevNode = it;
//         }
//         cout << endl;
//         return NULL;
//     }
// };