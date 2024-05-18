#include <iostream>
using namespace std;

int main()
{
    int n, fact = 1;
    cin >> n;
    if (n > 0)
    {
        for (int i = n; i > 0; i--)
        {
            fact *= i;
        }
        cout << fact << endl;
    }
    else if (n == 0)
        cout << fact << endl;
    else
        cout << "Error" << endl;
    return 0;
}