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
    DNode* head;
    DNode* tail;
    unordered_map<int, DNode*> cache;
    int capacity;

    void deleteElement(DNode* node) {
        DNode* prevNode = node->prev;
        DNode* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void putAtTail(DNode* node) {
        DNode* prevNode = tail->prev;

        prevNode->next = node;
        node->prev = prevNode;

        node->next = tail;
        tail->prev = node;
    }

public:
    LRUCache(int capacity) {
        /*
           head and tail are Dummy nodes
           head : LRU
           tail : MRU
        */
        head = new DNode();
        tail = new DNode();
        head->next = tail;
        tail->prev = head;

        cache = {};
        this->capacity = capacity;
    }

    int get(int key) {
        /*
        If not present in Cache, return -1
        If present in Cache, update it to MRU
        */

        if (cache.find(key) == cache.end()) {
            return -1;
        }

        DNode* node = cache[key];
        int nodeVal = node->val;
        deleteElement(node);
        putAtTail(node);

        return nodeVal;
    }

    void put(int key, int val) {
        /*
        If present in cache, then update it to MRU
        If not present, then add it to MRU
        check for the capacity overflow
        */

        if (cache.find(key) != cache.end()) {
            deleteElement(cache[key]);
        }

        DNode* node = new DNode(key, val);
        putAtTail(node);
        cache[key] = node;

        if (cache.size() > capacity) {
            DNode* lruNode = head->next;
            cache.erase(lruNode->key);
            deleteElement(lruNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */