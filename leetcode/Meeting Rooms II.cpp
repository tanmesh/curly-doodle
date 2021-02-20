class cmp {
    static const int start = 0;
    static const int end = 1;
public:
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
        if (a.first == b.first) {
            if (a.second == start && b.second == end) {
                return true;
            }
        }
        return a.first > b.first;
    }
};

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        static const int start = 0;
        static const int end = 1;

        typedef priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> my_pq;
        my_pq pq;

        for (auto interval : intervals) {
            pq.push({interval[0], start});
            pq.push({interval[1], end});
        }

        int result = -1, currentSum = 0;
        while (!pq.empty()) {
            if (pq.top().second == start) {
                ++currentSum;
            }
            if (pq.top().second == end) {
                --currentSum;
            }

            result = max(result, currentSum);
            pq.pop();
        }

        return result;
    }
};