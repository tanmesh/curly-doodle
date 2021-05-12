class Solution {
    void dfs(Node* root, int target, Node* &targetNode, unordered_map<Node*, Node*> &nodeParentMap) {
        if(root->data == target) {
            targetNode = root;
        }
        if(root->left != NULL) {
            nodeParentMap[root->left] = root;
            dfs(root->left, target, targetNode, nodeParentMap);    
        }
        if(root->right != NULL) {
            nodeParentMap[root->right] = root;
            dfs(root->right, target, targetNode, nodeParentMap);    
        }        
    }
    
    void debug(Node* currNode, queue<Node*> q, int burnTime) {
        cout << currNode->data << " " << burnTime << endl;
        queue<Node*> tmpQ = q;
        while(!tmpQ.empty()) {
            cout << "Queue --> " << tmpQ.front()->data << endl;
            tmpQ.pop();
        }
    }
    int getBurnTime(Node* root, unordered_map<Node*, Node*> nodeParentMap) {
        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        q.push(root);
        int burnTime = -1;
        
        while(!q.empty()) {
            int qSize = q.size();
            for(int i=0; i<qSize; ++i) {
                Node* currNode = q.front();
                q.pop();
                
                visited[currNode] = true;
                
                if(nodeParentMap.find(currNode) != nodeParentMap.end()) {
                    Node* parent = nodeParentMap[currNode];
                    if(visited[parent] == false) {
                        q.push(parent);
                    }
                }
                if(currNode->left != NULL && visited[currNode->left] == false) {
                    q.push(currNode->left);
                }
                if(currNode->right != NULL && visited[currNode->right] == false) {
                    q.push(currNode->right);
                }
            }
            ++burnTime;
        }
        
        return burnTime;
    }
    
    public:
    int minTime(Node* root, int target) {
        Node* targetNode = NULL;
        
        unordered_map<Node*, Node*> nodeParentMap;
        dfs(root, target, targetNode, nodeParentMap);
        
        return getBurnTime(targetNode, nodeParentMap);
    }
};