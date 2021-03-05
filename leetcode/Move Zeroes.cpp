class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) {
            return;
        }
        
        int onePtr = 0, zeroPtr = 0;
        while(onePtr < n && zeroPtr < n) {
            while(onePtr < n && nums[onePtr] == 0) {
                ++onePtr;
            }
            if(onePtr >= n) {
                return; 
            }
            
            while(zeroPtr < n && nums[zeroPtr] != 0) {
                ++zeroPtr;
            }
            if(zeroPtr >= n) {
                return;
            }
            
            if(onePtr > zeroPtr) {
                swap(nums[onePtr], nums[zeroPtr]);   
            }
            
            ++onePtr;
        }
    }
};