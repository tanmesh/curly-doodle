class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (auto stone : stones) { // N * logN
            pq.push(stone);
        }

        while (pq.size() > 1) { // N * (1 + logN + 1 + logN + logN) ==> N * logN
            int x = pq.top();
            pq.pop();

            int y = pq.top();
            pq.pop();

            pq.push(x - y);
        }

        return pq.top();
    }
};