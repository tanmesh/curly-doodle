class cmp {
public:
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashTable;
        for (auto num : nums) {
            if (hashTable.find(num) == hashTable.end()) {
                hashTable.insert({num, 1});
            } else {
                ++hashTable[num];
            }
        }

        typedef priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> my_pq;
        my_pq pq;

        for (auto it : hashTable) {
            pq.push(it);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        return result;
    }
};


/*
    1 --> 3
    2 --> 2
    3 --> 1
    4 --> 5


    heap size = 2
    (4,5), (1,3)            #distint * log(k)


    a, aa, z
*/