#include <ctime>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

class DLinkedList {
public:
    int val;
    DLinkedList* next;
    DLinkedList* prev;
    
    DLinkedList() {
        next = NULL;
        prev = NULL;
    }
    
    DLinkedList(int x) {
        val = x;
        next = NULL;
        prev = NULL;
    }
};

class MyLinkedList {
public:
    DLinkedList* head;
    DLinkedList* tail;
    int size;
    
    MyLinkedList() {
        size = 0;
        head = new DLinkedList();
        tail = new DLinkedList();
        head->next = tail;
        tail->prev = head;
    }
    
    DLinkedList* getNodeAtIndex(int index) {
        DLinkedList* curr = head->next;
        int i = 0;
        while(curr != tail) {
            if(i == index) {
                break;
            }
            ++i;
            curr = curr->next;
        }
        return curr;
    }
    
    bool validIndex(int index) {
        if(index < 0 || index > size) {
            return false;
        }
        return true;
    }
    
    int get(int index) {
        if(!validIndex(index) || (index == size)) {
            return -1;
        }
        
        DLinkedList* node = getNodeAtIndex(index);
        return node->val;
    }
    
    void addAtHead(int val) {
        DLinkedList* newNode = new DLinkedList(val);
        
        DLinkedList* headNext = head->next;
        
        head->next = newNode;
        newNode->prev = head;
        
        newNode->next = headNext;
        headNext->prev = newNode;
        ++size;
    }
    
    void addAtTail(int val) {
        DLinkedList* newNode = new DLinkedList(val);
        
        DLinkedList* tailPrev = tail->prev;
        
        tailPrev->next = newNode;
        newNode->prev = tailPrev;
        
        newNode->next = tail;
        tail->prev = newNode;
        ++size;
    }
    
    void insertBefore(DLinkedList* node, DLinkedList* nodeToInsert) {
        DLinkedList* nodePrev = node->prev;
        nodePrev->next = nodeToInsert;
        nodeToInsert->prev = nodePrev;
        
        nodeToInsert->next = node;
        node->prev = nodeToInsert;
        
        ++size;
    }
    
    void addAtIndex(int index, int val) {
        if(!validIndex(index)) {
            return;
        }
        
        if(index == 0) {
            addAtHead(val);
        } else if(index == size) {
            addAtTail(val);
        } else {
            DLinkedList* newNode = new DLinkedList(val);
            DLinkedList* node = getNodeAtIndex(index);
            insertBefore(node, newNode);    
        }
    }
    
    void removeNode(DLinkedList* node) {
        DLinkedList* nodePrev = node->prev;
        DLinkedList* nodeNext = node->next;
        
        nodePrev->next = nodeNext;
        nodeNext->prev = nodePrev;
        --size;
    }
    
    void deleteAtIndex(int index) {
        if(!validIndex(index) || index == size) {
            return;
        }
        DLinkedList* node = getNodeAtIndex(index);
        removeNode(node);
    }
};

int main() {
	
	MyLinkedList* l = new MyLinkedList();
	l->addAtHead(1);
	l->addAtTail(3);
	l->addAtIndex(1,2);
	cout  << l->get(1) << endl;
	l->deleteAtIndex(2);
	cout << l->get(1) << endl;

	return 0;
}
















