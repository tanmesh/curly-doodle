class Solution {
    unordered_map<int, int> dp;
public:
    int climbStairs(int n) {
        if(n < 2) {
            dp[n] = 1;
        }
        if(dp.find(n) == dp.end()) {
            dp[n] = climbStairs(n - 1) + climbStairs(n - 2);    
        }
        return dp[n];
    }
};