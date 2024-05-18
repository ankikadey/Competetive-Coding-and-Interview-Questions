#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Rectangle
{
public:
    int length;
    int breadth;
    int getArea(int length, int breadth)
    {
        return length * breadth;
    }
};

int main()
{
    int l, b;
    cin >> l >> b;
    Rectangle rect;

    int area = rect.getArea(l, b);
    cout << area << endl;

    return 0;
}