#include <iostream>
#include <cmath>
class Solution {
public:
    int isPrime(int A) {
        if (A <= 1) {
            return 0; // 0 indicates false (not prime)
        }

        int sqrtA = sqrt(A);

        for (int i = 2; i <= sqrtA; ++i) {
            if (A % i == 0) {
                return 0; // 0 indicates false (not prime)
            }
        }

        return 1; // 1 indicates true (prime)
    }
};
