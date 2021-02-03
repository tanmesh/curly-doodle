class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> overallDegree(N + 1, 0); // InDegree - OutDegree

        // O(trustLength)T
        for (auto it : trust) {
            int fromNode = it[0];
            int toNode = it[1];
            overallDegree[fromNode]--;
            overallDegree[toNode]++;
        }

        for (int i = 1; i <= N; ++i) {
            if (overallDegree[i] == N - 1) {
                return i;
            }
        }

        return -1;
    }
};