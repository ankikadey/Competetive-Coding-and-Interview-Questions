#include <iostream>
#include <vector>
using namespace std;

vector<int> printDivisors(int n)
{
    vector<int> divisors;
    for (int i = 1; i <= n; ++i)
    {
        if (n % i == 0)
        {
            divisors.push_back(i);
        }
    }
    return divisors;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> divisors = printDivisors(n);
    for (int i = 0; i < divisors.size(); ++i)
    {
        cout << divisors[i] << " ";
    }
    return 0;
}
