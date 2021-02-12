class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        unordered_map<int, vector<pair<int, int>>> pointsHash;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto point : points) {
            int x = point[0];
            int y = point[1];
            int dis = x * x + y * y;
            pointsHash[dis].push_back({x, y});

            pq.push(dis);
        }

        vector<vector<int>> result;
        while (K > 0) {
            int closestDis = pq.top();
            pq.pop();

            for (auto it : pointsHash[closestDis]) {
                if (K > 0) {
                    result.push_back({it.first, it.second});
                    K--;
                }
            }

        }

        return result;
    }
};