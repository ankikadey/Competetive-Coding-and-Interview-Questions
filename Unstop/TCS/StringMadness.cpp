#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.size();

    // Check if all characters are the same
    bool allsame = all_of(s.begin(), s.end(), [&](char c)
                          { return c == s[0]; });

    // Check if the string is a palindrome
    bool ispalindrome = equal(s.begin(), s.begin() + n / 2, s.rbegin());

    if (allsame)
        cout << 0 << endl;
    else if (ispalindrome)
        cout << n - 1 << endl;
    else
        cout << n << endl;

    return 0;
}
