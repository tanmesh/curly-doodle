class Solution {
public:
    unordered_map<int, bool> dp;
    
    bool wordBreak(string s, vector<string>& wordDict, int start = 0) {
        if(dp.find(start) == dp.end()) {
            if(start == s.length()) {
                return true;
            }
            dp[start] = false;
            for(int i = 0; i < wordDict.size(); ++i) {
                int len = wordDict[i].length();
                string sub = s.substr(start, len);
                if(wordDict[i] == sub) {
                    dp[start] = dp[start] || wordBreak(s, wordDict, start + len);
                }
            }    
        }
        return dp[start];
    }
};