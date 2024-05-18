#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    float s, e, w;
    cin >> s >> e >> w;
    for (float i = s; i <= e; i += w)
    {
        float cel = (i - 32) * 5 / 9;
        if (cel >= 0)
        {
            cout << i << "\t" << floor(cel) << endl;
        }
        else
        {
            cout << i << "\t" << ceil(cel) << endl;
        }
    }

    return 0;
}