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
private:
    void findParent(TreeNode* currNode, TreeNode* par, unordered_map<TreeNode*, TreeNode*> &parent) {
        if (currNode != NULL) {
            parent[currNode] = par;
            findParent(currNode->left, currNode, parent);
            findParent(currNode->right, currNode, parent);
        }
    }

    void dfs(TreeNode* node, int K, vector<int> &ans, unordered_map<TreeNode*, TreeNode*> &parent, unordered_set<TreeNode*> &visit) {
        if (visit.find(node) != visit.end()) {
            return;
        }
        visit.insert(node);

        if (K == 0) {
            ans.push_back(node->val);
            return;
        }

        if (node->left != NULL) { dfs(node->left, K - 1, ans, parent, visit); }
        if (node->right != NULL) { dfs(node->right, K - 1, ans, parent, visit); }

        TreeNode* p = parent[node];
        if (p != NULL) {
            dfs(p, K - 1, ans, parent, visit);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if (root == NULL) {
            return {};
        }

        unordered_map<TreeNode*, TreeNode*> parent;
        findParent(root, NULL, parent);

        vector<int> ans;
        unordered_set<TreeNode*> visit;
        dfs(target, K, ans, parent, visit);

        return ans;
    }
};