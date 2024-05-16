#include <iostream>
#include <vector>
using namespace std;

pair<int, int> find_flower_indices(int N, int t, vector<int> &a)
{
    // Initialize two pointers
    int i = 0, j = N - 1;

    // Search for pair sum equal to 't'
    while (i < j)
    {
        int total = a[i] + a[j];
        if (total == t)
        {
            return {i, j};
        }
        else if (total < t)
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    // No valid pair found
    return {-1, -1};
}

int main()
{
    int N, t;
    cin >> N >> t;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    auto result = find_flower_indices(N, t, a);
    if (result.first != -1)
    {
        cout << result.first << " " << result.second;
    }
    else
    {
        cout << "No valid pair found.";
    }

    return 0;
}
