class Solution {
public:
    vector<int> findIntersection(unordered_set<int> nums1, unordered_set<int> nums2) {
        vector<int> result;
        for (auto it : nums1) {
            if (nums2.find(it) != nums2.end()) {
                result.push_back(it);
            }
        }

        return result;
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> nums1Set, nums2Set;

        for (auto it : nums1) {
            nums1Set.insert(it);
        }

        for (auto it : nums2) {
            nums2Set.insert(it);
        }

        vector<int> result = findIntersection(nums1Set, nums2Set);

        return result;
    }
};