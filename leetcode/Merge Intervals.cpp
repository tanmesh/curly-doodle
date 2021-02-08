class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        vector<int> bound = intervals[0];

        for (auto interval : intervals) {
            int x = interval[0];
            int y = interval[1];

            if (bound[0] < x && bound[1] < x) {
                // no overlapping
                ans.push_back(vector<int> {bound[0], bound[1]});
                bound = interval;
            }

            bound[0] = min(bound[0], x);
            bound[1] = max(bound[1], y);
        }

        ans.push_back(vector<int> {bound[0], bound[1]});

        return ans;
    }
};