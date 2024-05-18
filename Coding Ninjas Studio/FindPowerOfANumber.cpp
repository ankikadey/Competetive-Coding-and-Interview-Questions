#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int n, p, res = 1;
    cin >> n >> p;
    for (int i = 0; i < p; i++)
    {
        res *= n;
    }
    cout << res << endl;
    return 0;
}