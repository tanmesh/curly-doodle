class Solution {
    bool isValidCapacity(vector<int>& weights, int days, int capacity) {
        int currentCapacity = 0;
        for(int i=0; i<weights.size(); ++i) {
            if(currentCapacity + weights[i] > capacity) {
                currentCapacity = 0;
                --days;
            }
            currentCapacity += weights[i];
            
        }
        return days > 0;
    }
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int low = 1*1, high = 5*10000*500+1;
        
        for(int i=0; i<weights.size(); ++i) {
            low = max(low, weights[i]);
        }
        
        int result = INT_MAX;
        while(low <= high) {
            int mid = low + (high - low)/2;
            
            if(isValidCapacity(weights, D, mid)) {
                result = min(result, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    }
};