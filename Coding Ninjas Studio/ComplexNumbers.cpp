#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class ComplexNumbers
{
    // Complete this class
private:
    int real;
    int imaginary;

public:
    ComplexNumbers(int r, int i) : real(r), imaginary(i) {}

    void plus(const ComplexNumbers &other)
    {
        real += other.real;
        imaginary += other.imaginary;
    }

    void multiply(const ComplexNumbers &other)
    {
        int temp_real = real * other.real - imaginary * other.imaginary;
        imaginary = real * other.imaginary + imaginary * other.real;
        real = temp_real;
    }

    void print()
    {
        cout << real << " + "
             << "i" << imaginary << endl;
    }
};

int main()
{
    int real1, imaginary1, real2, imaginary2;

    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;

    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    int choice;
    cin >> choice;

    if (choice == 1)
    {
        c1.plus(c2);
        c1.print();
    }
    else if (choice == 2)
    {
        c1.multiply(c2);
        c1.print();
    }
    else
    {
        return 0;
    }
}