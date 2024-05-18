#include <iostream>
using namespace std;

const int MOD = 1000000007;

// Function to multiply two matrices A and B
void multiply_matrices(long long A[2][2], long long B[2][2]) {
    long long temp[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            temp[i][j] = (A[i][0] * B[0][j] + A[i][1] * B[1][j]) % MOD;
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            A[i][j] = temp[i][j];
        }
    }
}

// Function to calculate A^n using matrix exponentiation
void power_matrix(long long A[2][2], int n) {
    if (n == 1) {
        return;
    }
    long long temp[2][2] = {{1, 1}, {1, 0}};
    power_matrix(A, n / 2);
    multiply_matrices(A, A);
    if (n % 2 != 0) {
        multiply_matrices(A, temp);
    }
}

// Function to find the N'th Fibonacci number
long long fibonacciNumber(int N) {
    if (N == 1 || N == 2) {
        return 1;
    }
    long long base_matrix[2][2] = {{1, 1}, {1, 0}};
    power_matrix(base_matrix, N - 1);
    return base_matrix[0][0];
}
int main() {
    int N;
    cin >> N;
    long long result = fibonacciNumber(N) % MOD;
    cout << result << endl;
    return 0;
}
