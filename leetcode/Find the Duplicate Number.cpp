// Solution 2: using sort, O(NLogN)T, O(1)S
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int first = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int second = nums[i];
            if (first == second) {
                return first;
            }
            first = second;
        }
        return 0;
    }
};


// Solution 1: using Map, O(N)T, O(N)S
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         unordered_map<int, int> mp;
//         for(int i=0; i<nums.size(); ++i) {
//             ++mp[nums[i]];
//             if(mp[nums[i]] == 2) {
//                 return nums[i];
//             }
//         }
//         return 0;
//     }
// };