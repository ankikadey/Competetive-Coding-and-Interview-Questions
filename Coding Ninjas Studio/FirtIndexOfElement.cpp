#include <iostream>
using namespace std;
int findFirstOccurrence(int arr[], int n, int x)
{
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1; // If x is not present in the array
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int x;

    cin >> x;

    int index = findFirstOccurrence(arr, n, x);
    if (index != -1)
    {
        cout << index << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
