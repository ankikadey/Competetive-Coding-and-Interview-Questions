#include <iostream>
#include <vector>

using namespace std;

vector<int> intersect(const vector<int> &A, const vector<int> &B) {
    vector<int> result;
    int i = 0, j = 0;

    while (i < A.size() && j < B.size()) {
        if (A[i] < B[j]) {
            i++;
        } else if (A[i] > B[j]) {
            j++;
        } else {
            result.push_back(A[i]);
            i++;
            j++;
        }
    }

    return result;
}

// Function to print the vector
void printVector(const vector<int> &v) {
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
    vector<int> A1 = {1, 2, 3, 3, 4, 5, 6};
    vector<int> B1 = {3, 3, 5};

    vector<int> A2 = {1, 2, 3, 3, 4, 5, 6};
    vector<int> B2 = {3, 5};

    cout << "Input 1:\nA: ";
    printVector(A1);
    cout << "B: ";
    printVector(B1);

    cout << "Output 1: ";
    printVector(intersect(A1, B1));

    cout << "Input 2:\nA: ";
    printVector(A2);
    cout << "B: ";
    printVector(B2);

    cout << "Output 2: ";
    printVector(intersect(A2, B2));

    return 0;
}
