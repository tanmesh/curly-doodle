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
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> GSet;
        for (auto it : G) {
            GSet.insert(it);
        }

        int componentCount = 0;
        ListNode* tmp = head;
        while (tmp != NULL) {
            int nodeVal = tmp->val;

            if (GSet.find(nodeVal) != GSet.end()) {
                while (tmp != NULL && GSet.find(tmp->val) != GSet.end()) {
                    tmp = tmp->next;
                }
                ++componentCount;
            }
            if (tmp != NULL) {
                tmp = tmp->next;
            }
        }

        return componentCount;
    }
};