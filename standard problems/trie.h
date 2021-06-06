#ifndef TRIE_H
#define TRIE_H

#include <ctime>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    string prefix;
    bool terminal;

    TrieNode() {
        terminal = false;
    }
};

class Trie {
private:
    TrieNode *root;
public:
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *node = root;
        
        for(auto ch: word) {
            if(node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->terminal = true;
        node->prefix = word;
    }
    
    bool search(string word) {
        TrieNode *node = root;

        for(auto ch: word) {
            if(node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }

        return node->terminal;
    }

    // string findLongestWord() {
    //     string longestWord = "";
        
    //     TrieNode *node = this->root;
    //     stack<TrieNode *> stack;
    //     stack.push(node);
    //     while(!stack.empty()) {
    //         TrieNode* node = stack.pop();
            
    //     }
    // }
};

#endif
