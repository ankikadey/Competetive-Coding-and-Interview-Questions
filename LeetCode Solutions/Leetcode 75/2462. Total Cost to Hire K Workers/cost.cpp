#include <vector>
#include <iostream>
#include <queue>
using namespace std;

#define ll long long
#define pll pair<long long, long long>
class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int C)
    {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        ll ans = 0, n = costs.size(), a = 0, b = n - 1;
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        while (a < C && a <= b)
            pq.push({costs[a], a}), a++;
        while (b >= n - C && a <= b)
            pq.push({costs[b], b}), b--;
        while (k--)
        {
            ll cost = pq.top().first, pos = pq.top().second;
            pq.pop(), ans += cost;
            if (a <= b)
            {
                if (pos < a)
                    pq.push({costs[a], a}), a++;
                else
                    pq.push({costs[b], b}), b--;
            }
        }
        return ans;
    }
};