class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        if(n < 2) {
            return true;
        }
        
        int direction = A[0] - A[1];
        for(int i=2; i<n; ++i) {
            int difference = A[i - 1] - A[i];
            if(direction == 0) {
                direction = difference;
            }
            if(difference * direction < 0) {
                return false;
            }
        }
        return true;
    }
};