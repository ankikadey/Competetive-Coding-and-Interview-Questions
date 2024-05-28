#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <xatomic.h>
using namespace std;

int nC3(int n) {
    if (n < 3)
        return 0;
    return (n * (n - 1) * (n - 2)) / 6;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    map<int, int> freq;
    for (int i : a)
        freq[i]++;

    int ans = 0;
    for (auto it = freq.begin(); it != freq.end(); it++) {
        ans += nC3(it->second);
    }

    cout << ans << endl;

    return 0;
}