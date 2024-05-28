#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int m, n;
    cin >> n;
    cin >> m;
    int arr[m][2];

    for(int i = 0; i < m; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }

    for(int i = 1; i <= n; i++)
    {
        int received = 0;
        int gave = 0;
        // COunt no. of gifts every person gave and received
        for(int j = 0; j < m; j++)
        {
            if(arr[j][0] == i)
                gave++;
            if(arr[j][1] == i)
                received++;
        }
        // Youngest person will receive n-1 gifts and give none
        if(received == n-1 && gave == 0)
        {
            cout << i << endl;
            return 0;
        }
    }
    // No youngest member found
    cout << -1 << endl;
    return 0;
}