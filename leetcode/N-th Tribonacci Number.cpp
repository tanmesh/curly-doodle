class Solution {
    unordered_map<int, int> cache;
public:
    int tribonacci(int n) {
        if(cache.find(n) == cache.end()) {
            if(n == 0) {
                return 0;
            }   
            if(n < 3) {
                return 1;
            }
            cache[n] = tribonacci(n-3) + tribonacci(n-2) + tribonacci(n-1);
        }
        return cache[n];
    }
};