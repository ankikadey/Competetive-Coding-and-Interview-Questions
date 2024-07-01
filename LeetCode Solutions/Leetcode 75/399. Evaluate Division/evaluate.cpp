#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    double an1 = -1;
    void dfs(string &root, string &stop, map<string, vector<pair<string, double>>> &mp, double ans, map<string, int> &check)
    {
        if (root == stop)
        {
            an1 = ans;
            return;
        }
        if (mp.find(root) == mp.end())
        {
            return;
        }
        check[root] = -1;

        for (auto i : mp[root])
        {
            string node = i.first;
            if (check[node] != -1)
            {
                double bal = i.second;
                dfs(node, stop, mp, ans * bal, check);
            }
        }
        return;
    }

    vector<double> calcEquation(vector<vector<string>> &eq, vector<double> &val, vector<vector<string>> &qr)
    {

        map<string, vector<pair<string, double>>> mp;
        int n = eq.size();

        // creating an adjencency list by the help of map
        for (int i = 0; i < n; ++i)
        {
            mp[eq[i][0]].push_back({eq[i][1], val[i]}); // for a/b
            double ch = 1 / val[i];
            mp[eq[i][1]].push_back({eq[i][0], ch}); // for b/a
        }
        vector<double> an;

        for (int i = 0; i < qr.size(); ++i)
        {
            an1 = -1;
            map<string, int> check;
            // if start node is present is our adjencency list
            if (mp.find(qr[i][0]) != mp.end())
                dfs(qr[i][0], qr[i][1], mp, 1, check);
            an.push_back(an1);
        }
        return an;
    }
};