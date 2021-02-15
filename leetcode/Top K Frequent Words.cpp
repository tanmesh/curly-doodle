class cmp {
public:
    bool operator() (const pair<string, int> &a, const pair<string, int> &b) const {
        int frequency1 = a.second;
        int frequency2 = b.second;

        string word1 = a.first;
        string word2 = b.first;
        if (frequency1 == frequency2 ) {
            return word1 < word2;
        }
        return frequency1 > frequency2;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int K) {
        unordered_map<string, int> hashTable;
        for (auto word : words) {
            if (hashTable.find(word) == hashTable.end()) {
                hashTable.insert({word, 0});
            } else {
                hashTable[word]++;
            }
        }

        typedef pair<string, int> p;
        typedef priority_queue<p, vector<p>, cmp> mypq_type;
        mypq_type pq;

        for (auto wordFreq : hashTable) {
            pq.push(wordFreq);
            if (pq.size() > K) {
                pq.pop();
            }
        }

        vector<string> result;
        while (!pq.empty()) {
            string word = pq.top().first;
            result.push_back(word);

            pq.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};