#include <iostream>
using namespace std;

// Function to calculate (base^exponent) % modulus
long long powerMod(long long base, long long exponent, long long modulus) {
    long long result = 1;
    base %= modulus;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent /= 2;
    }

    return result;
}

// Function to calculate A^(B^C) % M
long long calculatePower(long long A, long long B, long long C, long long M) {
    long long powerBC = powerMod(B, C, M - 1); // Using Euler's theorem: a^(phi(m)) = 1 (mod m) if gcd(a, m) = 1
    long long result = powerMod(A, powerBC, M);
    return result;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long A, B, C, M;
        cin >> A >> B >> C >> M;

        long long result = calculatePower(A, B, C, M);
        cout << result << endl;
    }

    return 0;
}

/*5
1 1 1 1000000007
1 2 3 5
2 3 5 7
3 6 9 11
5 5 1 17
*/