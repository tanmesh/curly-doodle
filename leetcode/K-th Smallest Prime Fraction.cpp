class cmp {
public:
    bool operator() (const vector<int> &a, const vector<int> &b) const {
        return a[0] * b[1] > a[1] * b[0];
    }
};

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        typedef priority_queue<vector<int>, vector<vector<int>>, cmp> my_pq;
        my_pq pq;

        for (int i = 0; i < arr.size(); ++i) {
            for (int j = i + 1; j < arr.size(); ++j) {

                pq.push({arr[i], arr[j]});
                if (pq.size() > k) {
                    pq.pop();
                }
            }
        }

        return vector<int> {pq.top()[0], pq.top()[1]};
    }
};