#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int sumOfSquares(int n)
{
    int sum = 0;
    while (n > 0)
    {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool isGoodNumber(int n)
{
    int slow = n, fast = n;
    do
    {
        slow = sumOfSquares(slow);
        fast = sumOfSquares(sumOfSquares(fast));

        if (fast == 1)
        {
            return true;
        }
    } while (slow != fast);

    return false;
}

int main()
{
    int n;
    cin >> n;

    if (isGoodNumber(n))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}