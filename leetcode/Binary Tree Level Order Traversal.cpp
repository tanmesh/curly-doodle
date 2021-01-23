// Solution2: using Queue, O(#node)T, O(#node)S
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> traversal;

        if (root == NULL) {
            return traversal;
        }
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> t1 = {};

            int qSize = q.size();
            for (int i = 0; i < qSize; ++i) {
                TreeNode* currentNode = q.front();
                q.pop();

                t1.push_back(currentNode->val);

                if (currentNode->left != NULL) {
                    q.push(currentNode->left);
                }

                if (currentNode->right != NULL) {
                    q.push(currentNode->right);
                }
            }

            traversal.push_back(t1);
        }

        return traversal;
    }

};


// // Solution1: using Rec, O(#node)T, O(#node)S
// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:

//     void findTraverseOrderUsingRec(TreeNode* root, vector<vector<int>>& traversalOrder, int currentLevel) {
//         if(root == NULL) {
//             return;
//         }

//         if(traversalOrder.size() == currentLevel) {
//             vector<int> newLevel;
//             newLevel.push_back(root->val);
//             traversalOrder.push_back(newLevel);
//         } else {
//             traversalOrder[currentLevel].push_back(root->val);
//         }

//         findTraverseOrderUsingRec(root->left, traversalOrder, currentLevel+1);

//         findTraverseOrderUsingRec(root->right, traversalOrder, currentLevel+1);
//     }

//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> traversalOrder;
//         int level = 0;
//         findTraverseOrderUsingRec(root, traversalOrder, level);

//         return traversalOrder;
//     }
// };