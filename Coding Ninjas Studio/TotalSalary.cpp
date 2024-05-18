#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int basic, allow;
    float hra, da, pf;
    char ch;
    cin >> basic >> ch;
    hra = 0.20 * basic;
    da = 0.50 * basic;
    pf = 0.11 * basic;
    if (ch == 'A')
        allow = 1700;
    else if (ch == 'B')
        allow = 1500;
    else
        allow = 1300;
    int total = round(basic + hra + da + allow - pf);
    cout << total << endl;
    return 0;
}