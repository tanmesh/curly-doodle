class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n, 0);

        for (auto edge : edges) {
            int from = edge[0];
            int to = edge[1];

            ++inDegree[to];
        }

        vector<int> ans;
        for (int i = 0; i < inDegree.size(); ++i) {
            if (inDegree[i] == 0) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};