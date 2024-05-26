#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n % 2 == 0)
        cout << (2 * n);
    else
        cout << ((2 * n) - 1);

    return 0;
}
