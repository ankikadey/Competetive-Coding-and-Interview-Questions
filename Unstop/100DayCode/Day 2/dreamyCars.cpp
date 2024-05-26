#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the XOR of all subarray XORs
int getTotalXorOfSubarrayXors(const vector<int> &arr, int N) {
    int totalXor = 0; // Initialize result

    // Iterate over all elements of the array
    for (int i = 0; i < N; i++) {
        // Calculate the frequency of the current element in all subarrays
        int frequency = (i + 1) * (N - i);

        // If the frequency is odd, include the current element in the result
        if (frequency % 2 == 1) {
            totalXor ^= arr[i];
        }
    }

    // Return the total XOR of all subarray XORs
    return totalXor;
}

int main() {
    // Input size of the array
    int N;
    cin >> N;

    // Input array elements
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // Output the result
    cout << getTotalXorOfSubarrayXors(arr, N);

    return 0;
}
