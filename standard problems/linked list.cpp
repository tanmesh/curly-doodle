#include <ctime>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

class ListNode {
public:
	int val;
	ListNode* next;

	ListNode() {
		val = 0;
		next = NULL;
	}

	ListNode(int x) {
		val = x;
		next = NULL;
	}
 };

void buildListNode(ListNode* &head) {
	cout << "Enter N:\n";
	int N;
	cin >> N;
	cout << "Enter N values for Linked List:\n";

	ListNode* curr = head;
	while(N) {
		int val;
		cin >> val;

		ListNode* newNode = new ListNode(val);
		curr->next = newNode;
		curr = newNode;

		N--;
	}
}

void print(ListNode* head) {
	ListNode* curr = head;
	while(curr != NULL) {
		cout << curr->val << " ";
		curr = curr->next;
	}
	cout << endl;
}

ListNode* middleOfLinkedList(ListNode* head) {
	ListNode* slowPtr = head;
    ListNode* fastPtr = head;
    while(fastPtr != NULL && fastPtr->next != NULL) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    return slowPtr;
}

bool checkForPalindrome(ListNode* head, ListNode* middleNode, ListNode* tail) {
    while(head != middleNode) {
        if(head->val != tail->val) {
            return false;
        }
        head = head->next;
        tail = tail->next;
    }
    
    return true;
}

ListNode* reverseSecondHalf(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    
    while(curr != NULL) {
        ListNode* currNext = curr->next;
        
        curr->next = prev;
        prev = curr;
        
        curr = currNext;
    }
    
    return prev;
}

bool isPalindromicByReversingSecondHalf(ListNode* head) {
	ListNode* middleNode = middleOfLinkedList(head);
    
    ListNode* tail = reverseSecondHalf(middleNode);
    
    return checkForPalindrome(head, middleNode, tail);
}

bool isPalindromicUsingRecursion(ListNode* &head, ListNode* tail) {
    bool isPallindrmic = true;
    if(tail == NULL) {
        isPallindrmic = true;
    } else {
        isPallindrmic = isPalindromicUsingRecursion(head, tail->next);
        if(head->val != tail->val) {
            isPallindrmic = false;
        }
        head = head->next;
    }
    return isPallindrmic;
}

ListNode* getMiddle(ListNode* head) {
    ListNode* slowPtr = NULL;
    ListNode* fastPtr = head;
    while(fastPtr != NULL && fastPtr->next != NULL) {
        if(slowPtr == NULL) {
            slowPtr = head;
        } else {
            slowPtr = slowPtr->next;    
        }
        fastPtr = fastPtr->next->next;
    }
    return slowPtr;
}

void merge(ListNode*& head1, ListNode* &head2) {
    ListNode* curr1 = head1;
    ListNode* curr2 = head2;
    ListNode* prev1 = NULL;
    
    while(curr1 != NULL && curr2 != NULL) {
        if(curr1->val < curr2->val) {
            prev1 = curr1;
            curr1 = curr1->next;
        } else {
            ListNode* curr2Next = curr2->next;
            if(prev1 != NULL) {
                prev1->next = curr2;
            } else {
                head1 = curr2;
            }
            curr2->next = curr1;
            
            prev1 = curr2;
            curr2 = curr2Next;
        }
    }
    
    while(curr2 != NULL) {
        ListNode* curr2Next = curr2->next;
        if(prev1 != NULL) {
            prev1->next = curr2;
        } else {
            head1 = curr2;
        }
        curr2->next = curr1;

        prev1 = curr2;
        curr2 = curr2Next;
    }
}

void mergeSort(ListNode* &head) {
    if(head != NULL && head->next != NULL) {
        ListNode* middleNode = getMiddle(head);
        ListNode* middleNext = middleNode->next;  
        
        middleNode->next = NULL;
        
        mergeSort(head);
        mergeSort(middleNext);
        merge(head, middleNext);
    }
}

int main() {
	ListNode* head = new ListNode();
	buildListNode(head);
	head = head->next;

	// cout << "middleOfLinkedList: \n";
	// cout << middleOfLinkedList(head) << endl;

	// cout << isPalindromicByReversingSecondHalf(head) << endl;

	// cout << isPalindromicUsingRecursion(head, head) << endl;

	// cout << "Before sort:\n";
	// print(head);
	// mergeSort(head);
	// cout << "After sort:\n";
	// print(head);

	return 0;
}