#include <iostream>
using namespace std;

void swapNumber(int &a, int &b) {
	// Write your code here.
	a = a + b; //10,20. a = 10+20=30, b = 20
	b = a - b; // b = 30-20 = 10, a=30
	a = a - b; // a = 30-10 = 20, b = 10.
}

int main(int argc, char const *argv[])
{
    int a, b;
    cin >> a >> b;
    swapNumber(a, b);
    return 0;
}
