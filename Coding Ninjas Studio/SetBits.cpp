#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int countBits(int n)
{
    int count = 0;
    while (n > 0)
    {
        if (n & 1)
        {
            count++;
        }
        n >>= 1; // right shift by 1 to check the next bit
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    cout << countBits(n);
    return 0;
}