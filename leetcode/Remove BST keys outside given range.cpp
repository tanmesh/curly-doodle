class Solution {
    public:
    Node* removekeys(Node* root, int leftBound, int rightBound) {
        if(root == NULL) {
            return NULL;
        }
        root->left = removekeys(root->left, leftBound, rightBound);
        root->right = removekeys(root->right, leftBound, rightBound);
        
        if(root->data < leftBound) {
            Node* rightChild = root->right;
            delete root;
            return rightChild;
        } else if(root->data > rightBound) {
            Node* leftChild = root->left;
            delete root;
            return leftChild;
        } 
        return root;
    }
};