class Solution {
public:

    int findLowerBound(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                high = mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (nums[low] != target) {
            return -1;
        }
        return low;
    }

    int findUpperBound(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low + 1) / 2;
            if (nums[mid] == target) {
                low = mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (low == nums.size()) {
            return -1;
        }
        if (nums[low] != target) {
            return -1;
        }

        return low;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return vector<int> { -1, -1};
        }

        int lowerBound = findLowerBound(nums, target);

        int upperBound = findUpperBound(nums, target);

        return vector<int> {lowerBound, upperBound};
    }
};