#include <iostream>
#include <vector>
using namespace std;

int findLastOccurrenceIndex(const vector<int> &arr, int x)
{
    int n = arr.size();
    for (int i = n - 1; i >= 0; --i)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int x;
    cin >> x;

    int lastIndex = findLastOccurrenceIndex(arr, x);

    if (lastIndex != -1)
    {
        cout << lastIndex << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
