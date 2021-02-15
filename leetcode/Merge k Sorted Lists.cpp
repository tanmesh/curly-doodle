/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class cmp {
public:
    bool operator() (const int &a, const int &b) const {
        return a > b;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        typedef priority_queue<int, vector<int>, cmp> my_pq;
        my_pq pq;
        for (auto list : lists) {
            ListNode* currNode = list;
            while (currNode != NULL) {
                pq.push(currNode->val);
                currNode = currNode->next;
            }
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;
        while (!pq.empty()) {
            ListNode* node = new ListNode(pq.top());
            if (head == NULL && tail == NULL) {
                head = node;
            } else {
                tail->next = node;
            }
            tail = node;
            pq.pop();
        }

        return head;
    }
};