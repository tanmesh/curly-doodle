class cmp {
public:
    bool operator() (const pair<char, int> &a, const pair<char, int> &b) const {
        return a.second < b.second;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> hashTable;

        for (auto ch : s) {
            if (hashTable.find(ch) == hashTable.end()) {
                hashTable[ch] = 1;
            } else {
                hashTable[ch]++;
            }
        }

        typedef priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> my_pq;
        my_pq pq;

        for (auto pair : hashTable) {
            pq.push(pair);
        }

        string result = "";
        while (!pq.empty()) {
            pair<char, int> ch = pq.top();
            for (int i = 0; i < ch.second; ++i) {
                result += ch.first;
            }
            pq.pop();
        }

        return result;
    }
};