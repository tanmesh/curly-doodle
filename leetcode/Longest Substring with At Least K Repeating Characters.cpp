class Solution {
    int divideAndConquer(string s, int start, int end, int k) {
        unordered_map<char, int> counter;
        for(int i=start; i<=end; ++i) {
            ++counter[s[i]];
        }
        
        bool flag = true;
        for(auto it: counter) {
            if(it.second > 0 && it.second < k) {
                flag = false;
            }
        }
        
        if(flag == true) {
            return end - start + 1;
        }
        
        for(int i=start; i<=end; ++i) {
            int count = counter[s[i]];
            if(count > 0 && count < k) {
                int leftSide = divideAndConquer(s, start, i - 1, k);
                int rightSide = divideAndConquer(s, i + 1, end, k);
                return max(leftSide, rightSide);
            }
        }
        return end - start + 1;
    }
    
public:
    int longestSubstring(string s, int k) {
        return divideAndConquer(s, 0, s.length()-1, k);
    }
};