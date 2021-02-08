class Solution {
private:
    void twoSum(int beginIdx, vector<int>& nums, vector<vector<int>> &triples) {
        int i = beginIdx + 1, j = nums.size() - 1;

        while (i < j) {
            int sum = nums[beginIdx] + nums[i] + nums[j];

            if (sum == 0) {
                triples.push_back(vector<int> {nums[beginIdx], nums[i], nums[j]});
                ++i, --j;
                while (i < j && nums[i - 1] == nums[i]) {
                    ++i;
                }
            }

            if (sum < 0) {
                ++i;
            } else if (sum > 0) {
                --j;
            }
        }
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) { // O(NlogN + N^2)T = O(N^2)T
        sort(nums.begin(), nums.end()); // O(NlogN)T

        vector<vector<int>> triples;
        for (int i = 0; i < nums.size() && nums[i] <= 0; ++i) { // O(N^2)T
            if (i == 0 || nums[i - 1] != nums[i]) {
                twoSum(i, nums, triples); // O(N)T
            }
        }

        return triples;
    }
};