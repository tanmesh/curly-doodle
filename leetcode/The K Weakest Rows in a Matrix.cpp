// Solution 2: binary search, pair, sort , O(MlogN+MlogM)T, O(M)S, row = N, col = M
class Solution {
public:
    int countOnes(vector<int>& row) {
        int low = 0, high = row.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (row[mid] == 1) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low + 1;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;

        vector<pair<int, int>> mp;

        // O(M*logN)
        for (int i = 0; i < mat.size(); ++i) { // O(M)
            int ones = countOnes(mat[i]); // O(logN)
            mp.push_back({ones, i}); // O(1),
        }

        sort(mp.begin(), mp.end()); // O(MlogM)

        // O(K)
        for (int i = 0; i < k; ++i) {
            ans.push_back(mp[i].second); // O(1)
        }

        return ans;
    }
};

// // Solution 1: linear search and pair and sort , O(N*M + MlogM)T, O(M)S, row = N, col = M
// class Solution {
// public:
//     int countOnes(vector<int>& row) {
//         int ones = 0;
//         for(auto it: row) {
//             if(it == 1) {
//                 ++ones;
//             }
//         }

//         return ones;
//     }

//     vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
//         vector<int> ans;

//         vector<pair<int, int>> mp;

//         // O(N*M)
//         for(int i=0; i<mat.size(); ++i) { // O(M)
//             int ones = countOnes(mat[i]); // O(N)
//             mp.push_back({ones, i}); // O(1),
//         }

//         sort(mp.begin(), mp.end()); // O(MlogM)

//         // O(K)
//         for(int i=0; i<k; ++i) {
//             ans.push_back(mp[i].second); // O(1)
//         }

//         return ans;
//     }
// };