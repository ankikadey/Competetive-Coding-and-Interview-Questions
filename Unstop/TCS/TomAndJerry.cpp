#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findCookie(vector<int>& stream, int k) {
    nth_element(stream.begin(), stream.begin() + k - 1, stream.end(), greater<int>());
    return stream[k - 1];
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> stream(n);
    for (int i = 0; i < n; ++i) {
        cin >> stream[i];
    }

    int cookiePosition = findCookie(stream, k);
    cout << cookiePosition << endl;

    return 0;
}
