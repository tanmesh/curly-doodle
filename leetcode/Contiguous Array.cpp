class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hashMap;

        int maxArrayLen = 0, currSum = 0;

        hashMap[0] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                currSum += -1;
            } else {
                currSum += 1;
            }

            if (hashMap.find(currSum) != hashMap.end()) {
                maxArrayLen = max(maxArrayLen, i - hashMap[currSum]);
            } else {
                hashMap[currSum] = i;
            }
        }

        return maxArrayLen;
    }
};