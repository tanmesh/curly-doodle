class Solution {
    unordered_map<int, bool> dp;
    unordered_set<string> hashMap;
    
    void segmentation(int start, string tmpResult, vector<string> &result, string s, unordered_set<string> &hashMap) {
        if(start == s.length()) {
            result.push_back(tmpResult.substr(0, tmpResult.length()-1));
        }
        for(int end = start; end < s.length(); ++end) {
            int len = end - start + 1;
            string substr = s.substr(start, len);
            if(hashMap.find(substr) != hashMap.end()) {
                segmentation(end + 1, tmpResult + substr + " ", result, s, hashMap);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto it: wordDict) {  
            hashMap.insert(it);
        }
        vector<string> result = {};
        string tmpResult = "";
        
        segmentation(0, tmpResult, result, s, hashMap);
        return result;
    }
};