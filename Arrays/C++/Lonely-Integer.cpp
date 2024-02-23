#include <iostream>
#include <vector>

using namespace std;

int lonelyInteger(vector<int> a) {
    for (int i : a) {
        if (count(a.begin(), a.end(), i) == 1) {
            return i;
        }
    }
    return -1; // Default return if no lonely integer is found (optional)
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int result = lonelyInteger(a);

    cout << result << '\n';

    return 0;
}
