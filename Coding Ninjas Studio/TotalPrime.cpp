#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool isPrime(int number)
{
    if (number <= 1)
    {
        return false;
    }

    for (int i = 2; i * i <= number; ++i)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}

int totalPrime(int start, int end)
{
    int count = 0;
    for (int i = start; i <= end; ++i)
    {
        if (isPrime(i))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int S, E;
    cin >> S >> E;
    cout << totalPrime(S, E);
    return 0;
}