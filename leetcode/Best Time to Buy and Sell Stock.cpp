class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> maxArray(n);
        maxArray[n-1] = prices[n-1];
        for(int i=n-2; i>=0; --i) {
            maxArray[i] = max(prices[i], maxArray[i+1]);
        }
        
        int profit = 0;
        for(int i=0; i<n-1; ++i) {
            profit = max(profit, maxArray[i+1] - prices[i]);
        }
        
        return profit;
    }
};

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         if(prices.size() == 0) {
//             return 0;
//         }
//         int buy = prices[0];
//         int sell = prices[0];
//         int profit = INT_MIN;
        
//         for(int i=1; i<prices.size(); ++i) {
//             if(prices[i] < buy) {
//                 profit = max(profit, sell - buy);
//                 buy = prices[i];
//                 sell = prices[i];
//             }
//             sell = max(sell, prices[i]);
//         }
//         return profit = max(profit, sell - buy);;
//     }
// };