#include <ctime>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

class DNode {
public:
    int key;
    int val;
    DNode* next;
    DNode* prev;
    
    DNode(int key, int val) {
        this->key = key;
        this->val = val;
        
        next = NULL;
        prev = NULL;
    }
    
    DNode() {
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
    int capacity;
    unordered_map<int, DNode*> cache;
    DNode* lru;
    DNode* mru;
    
    void remove(DNode* node) {
        cache.erase(node->key);
        
        DNode* nodePrev = node->prev;
        DNode* nodeNext = node->next;
        
        nodePrev->next = nodeNext;
        nodeNext->prev = nodePrev;
    }
    
    void addAtMru(DNode* node) {
        cache[node->key] = node;
        
        DNode* mruPrev = mru->prev;
        
        mruPrev->next = node;
        node->prev = mruPrev;
        
        node->next = mru;
        mru->prev = node;
    }
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        
        lru = new DNode();
        mru = new DNode();
        
        lru->next = mru;
        mru->prev = lru;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) {
            return -1;
        }
        DNode* node = cache[key];
        remove(node);
        addAtMru(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            remove(cache[key]);
        } else if(cache.size() == capacity) {
            remove(lru->next);
        }
        addAtMru(new DNode(key, value));
    }
};

int main() {
    LRUCache* lruCache = new LRUCache(2);
    lruCache->put(2,1);
    cout << "Put: 2, 1\n";
    lruCache->put(2,2);
    cout << "Put: 2, 2\n";
    cout << "Get: 2 -- " << lruCache->get(2) << endl;
    lruCache->put(1,1);
    cout << "Put: 1, 1\n";
    lruCache->put(4,2);
    cout << "Put: 4, 2\n";
    cout << "Get: 2 -- " << lruCache->get(2) << endl;

    return 0;
}