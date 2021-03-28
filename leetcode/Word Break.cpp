class Solution {
    unordered_map<int, bool> dp;
    unordered_set<string> hashMap;
    
    bool segmentation(string s, unordered_set<string> &hashMap, int start) {
        if(dp.find(start) == dp.end()) {
            if(start == s.length()) {
                return true;
            }
            dp[start] = false;
            for(int end = start; end < s.length(); ++end) {
                string sub = s.substr(start, end - start + 1);
                if(hashMap.find(sub) != hashMap.end()) {
                    dp[start] = segmentation(s, hashMap, end + 1);
                    if(dp[start] == true) {
                        break;
                    }       
                }
            }
        }
        return dp[start];
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto it: wordDict) {
            hashMap.insert(it);
        }
        return segmentation(s, hashMap, 0);
    }
};

// class Solution {
//     unordered_map<int, bool> dp;
// public:
//     bool wordBreak(string s, vector<string>& wordDict, int start = 0) {
//         if(dp.find(start) == dp.end()) {
//             if(start == s.length()) {
//                 return true;
//             }
//             dp[start] = false;
//             for(int i = 0; i < wordDict.size(); ++i) {
//                 int len = wordDict[i].length();
//                 string sub = s.substr(start, len);
//                 if(wordDict[i] == sub) {
//                     dp[start] = dp[start] || wordBreak(s, wordDict, start + len);
//                     if(dp[start] == true) {
//                         break;
//                     }
//                 }
//             }    
//         }
//         return dp[start];
//     }
// };