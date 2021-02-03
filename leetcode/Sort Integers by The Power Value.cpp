bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.second < b.second) {
        return true;
    }
    if (a.second == b.second && a.first < b.first) {
        return true;
    }
    return false;
}

class Solution {
public:

    unordered_map<int, int> dp;

    int findPower(int x) {
        if (dp.find(x) == dp.end()) {
            dp[x] = 0;
            if (x <= 1) {
                return 0;
            }
            if (x % 2 == 0) {
                dp[x] = 1 + findPower(x / 2);
            } else {
                dp[x] =  1 + findPower(3 * x + 1);
            }
        }
        return dp[x];
    }

    void calculatePowers(vector<pair<int, int>> &range) {
        for (int i = 0; i < range.size(); ++i) {
            range[i].second = findPower(range[i].first);
        }
    }

    int getKth(int lo, int hi, int k) {
        vector< pair<int, int> > range(hi - lo + 1);
        for (int i = 0; i < hi - lo + 1; ++i) {
            range[i].first = lo + i;
            range[i].second = 0;
        }

        calculatePowers(range);
        sort(range.begin(), range.end(), cmp);

        return range[k - 1].first;
    }
};