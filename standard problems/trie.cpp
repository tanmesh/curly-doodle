class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    string prefix;
};

class Trie {
private:
    TrieNode *root;
    char terminal;
public:
    
    Trie() {
        this->root = new TrieNode();
        this->terminal = false;
    }
    
    void insert(string word) {
        TrieNode *node = this->root;
        
        for(auto ch: word) {
            if(node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->children[this->terminal] = NULL;
        node->prefix = word;
    }
    
    string findLongestWord() {
        string longestWord = "";
        
        TrieNode *node = this->root;
        stack<TrieNode *> stack;
        stack.push(node);
        while(!stack.empty()) {
            TrieNode* node = stack.pop();
            
        }
    }
};

