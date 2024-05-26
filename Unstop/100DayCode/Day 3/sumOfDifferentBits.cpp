#include <iostream>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    long long sum = 0, ones = 0;
    for (int i = 0; i < b.size() - a.size() + 1; i++) {
        if (b[i] == '1') ones++;
    }
    for (int i = 0; i < a.size(); i++) {
        sum += (a[i] == '0' ? ones : b.size() - a.size() + 1 - ones);
        if (i != a.size() - 1) {
            if (b[i] == '1') ones--;
            if (b[i + b.size() - a.size() + 1] == '1') ones++;
        }
    }
    cout << sum;
    return 0;
}
