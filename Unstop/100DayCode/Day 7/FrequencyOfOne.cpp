#include <iostream>

using namespace std;

// Function to count the number of set bits in a number
int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main() {
    int N;
    cin >> N;

    int count = 0;
    for (int i = 1; i <= N; ++i) {
        count += countSetBits(i);
    }

    cout << count << endl;

    return 0;
}