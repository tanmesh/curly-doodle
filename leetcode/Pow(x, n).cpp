// Solution 2: Using iteration, O(logN)T, O(1)S
class Solution {
public:
    double myPow(double x, int n) {
        long long int N = n;
        if (N < 0) {
            x = 1 / x;
            N = N * (-1);
        }

        double ans = 1;
        double current_power = x;
        for (long long int i = N; i > 0; i = i / 2) {
            if ((i % 2) == 1) {
                ans = ans * current_power;
            }
            current_power = current_power * current_power;
        }

        return ans;
    }
};

// // Solution 1: using recursion, O(logN)T, O(logN)S
// class Solution {
// public:

//     double calculatePower(double x, long long int n) {
//         if(n == 0) {
//             return 1.0;
//         }
//         double half = calculatePower(x, n/2);

//         double power;
//         if(n%2 == 0) {
//             power = half * half;
//         } else {
//             power = x * half * half;
//         }

//         return power;
//     }

//     double myPow(double x, int n) {
//         long long int N = n;
//         if(N < 0) {
//             x = 1/x;
//             N = N * (-1);
//         }

//         return calculatePower(x, N);
//     }
// };