/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string encode(TreeNode* currNode) {
        if (currNode == NULL) {
            return "null";
        }
        string node = to_string(currNode->val);
        string leftPart = encode(currNode->left);
        string rightPart = encode(currNode->right);
        return node + "," + leftPart + "," + rightPart;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = encode(root);
        cout << str << endl;
        return str;
    }

    TreeNode* decode(queue<string>& q) {
        if (q.empty()) {
            return NULL;
        }
        string str = q.front();
        q.pop();

        if (str == "null") {
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(str));
        root->left = decode(q);
        root->right = decode(q);
        return root;
    }

    vector<string> getTreeFrom(string data) {
        vector<string> tree;

        string str = "";
        for (int i = 0; i < data.length(); ++i) {
            if (data[i] == ',') {
                tree.push_back(str);
                str = "";
            } else {
                str += data[i];
            }
        }

        return tree;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        vector<string> tree = getTreeFrom(data);

        queue<string> q;
        for (auto it : tree) {
            q.push(it);
        }

        return decode(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));