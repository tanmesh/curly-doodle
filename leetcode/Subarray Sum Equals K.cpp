class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        hashMap[0] = 1;

        int ans = 0;
        int sum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];

            if (hashMap.find(sum - k) != hashMap.end()) {
                ans += hashMap[sum - k];
            }

            hashMap[sum]++;
        }

        return ans;
    }
};