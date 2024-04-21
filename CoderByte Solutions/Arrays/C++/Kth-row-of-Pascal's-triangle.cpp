#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int A) {
    vector<int> result;
    if (A < 0) return result;
    result.resize(A + 1, 0);
    result[0] = 1;

    for (int i = 1; i <= A; i++) {
        for (int j = i; j >= 1; j--) {
            result[j] += result[j - 1];
        }
    }

    return result;
}

// Function to print the vector
void printVector(vector<int>& v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// Main function for testing
int main() {
    int k = 3;
    vector<int> result = getRow(k);
    cout << "Input: k = " << k << endl;
    cout << "Output: ";
    printVector(result);
    return 0;
}
