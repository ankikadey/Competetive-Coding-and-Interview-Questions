#include <iostream>
#include <xatomic.h>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &x : v)
        cin >> x;

    queue<int> q;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        while (!q.empty() && v[i] - q.front() >= 5000)
            q.pop();
        q.push(v[i]);
        mx = max(mx, (int)q.size());
    }
    cout << mx;
    return 0;
}
