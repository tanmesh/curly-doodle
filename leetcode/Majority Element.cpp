class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        int sum = 1;
        int ans = nums[0];
        for(int i = 1; i < n; ++i) {
            if(nums[i - 1] == nums[i]) {
                ++sum;
            } else {
                if(sum > n/2) {
                    ans = max(ans, nums[i - 1]);
                }
                sum = 1;
            }
        }
        if(sum > n/2) {
            ans = max(ans, nums[n - 1]);
        }
        
        return ans;
    }
};