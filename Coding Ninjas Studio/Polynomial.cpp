#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Polynomial
{
public:
    int *degCoeff; // Array to store coefficients
    int capacity;  // Capacity of the array

public:
    // Constructor
    Polynomial()
    {
        degCoeff = new int[1];
        degCoeff[0] = 0;
        capacity = 1;
    }

    // Copy Constructor
    Polynomial(const Polynomial &p)
    {
        capacity = p.capacity;
        degCoeff = new int[capacity];
        for (int i = 0; i < capacity; i++)
        {
            degCoeff[i] = p.degCoeff[i];
        }
    }

    // Copy Assignment Operator
    Polynomial &operator=(const Polynomial &p)
    {
        if (this == &p)
        {
            return *this;
        }
        delete[] degCoeff;
        capacity = p.capacity;
        degCoeff = new int[capacity];
        for (int i = 0; i < capacity; i++)
        {
            degCoeff[i] = p.degCoeff[i];
        }
        return *this;
    }

    // Function to set coefficient at a given degree
    void setCoefficient(int degree, int coefficient)
    {
        if (degree >= capacity)
        {
            int newCapacity = degree + 1;
            int *newCoeff = new int[newCapacity];
            for (int i = 0; i < capacity; i++)
            {
                newCoeff[i] = degCoeff[i];
            }
            for (int i = capacity; i < newCapacity; i++)
            {
                newCoeff[i] = 0;
            }
            delete[] degCoeff;
            degCoeff = newCoeff;
            capacity = newCapacity;
        }
        degCoeff[degree] = coefficient;
    }

    // Overloaded + operator for polynomial addition
    Polynomial operator+(const Polynomial &p) const
    {
        Polynomial result;
        int newCapacity = max(capacity, p.capacity);
        result.capacity = newCapacity;
        result.degCoeff = new int[newCapacity];
        for (int i = 0; i < newCapacity; i++)
        {
            result.degCoeff[i] = (i < capacity ? degCoeff[i] : 0) + (i < p.capacity ? p.degCoeff[i] : 0);
        }
        return result;
    }

    // Overloaded - operator for polynomial subtraction
    Polynomial operator-(const Polynomial &p) const
    {
        Polynomial result;
        int newCapacity = max(capacity, p.capacity);
        result.capacity = newCapacity;
        result.degCoeff = new int[newCapacity];
        for (int i = 0; i < newCapacity; i++)
        {
            result.degCoeff[i] = (i < capacity ? degCoeff[i] : 0) - (i < p.capacity ? p.degCoeff[i] : 0);
        }
        return result;
    }

    // Overloaded * operator for polynomial multiplication
    Polynomial operator*(const Polynomial &p) const
    {
        Polynomial result;
        int newCapacity = capacity + p.capacity - 1;
        result.capacity = newCapacity;
        result.degCoeff = new int[newCapacity];
        for (int i = 0; i < newCapacity; i++)
        {
            result.degCoeff[i] = 0;
        }
        for (int i = 0; i < capacity; i++)
        {
            for (int j = 0; j < p.capacity; j++)
            {
                result.degCoeff[i + j] += degCoeff[i] * p.degCoeff[j];
            }
        }
        return result;
    }

    // Function to print polynomial
    void print() const
    {
        bool firstTerm = true;
        for (int i = 1; i <= capacity - 1; i++)
        {
            if (degCoeff[i] != 0)
            {
                if (!firstTerm)
                {
                    cout << " ";
                }
                firstTerm = false;
                if (i == 0)
                {
                    cout << degCoeff[i];
                }
                else
                {
                    cout << degCoeff[i] << "x" << i;
                }
            }
        }
        cout << endl;
    }

    // Destructor
    ~Polynomial()
    {
        delete[] degCoeff;
    }
};

int main()
{
    int count1, count2, choice;
    cin >> count1;

    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];

    for (int i = 0; i < count1; i++)
    {
        cin >> degree1[i];
    }

    for (int i = 0; i < count1; i++)
    {
        cin >> coeff1[i];
    }

    Polynomial first;
    for (int i = 0; i < count1; i++)
    {
        first.setCoefficient(degree1[i], coeff1[i]);
    }

    cin >> count2;

    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];

    for (int i = 0; i < count2; i++)
    {
        cin >> degree2[i];
    }

    for (int i = 0; i < count2; i++)
    {
        cin >> coeff2[i];
    }

    Polynomial second;
    for (int i = 0; i < count2; i++)
    {
        second.setCoefficient(degree2[i], coeff2[i]);
    }

    cin >> choice;

    Polynomial result;
    switch (choice)
    {
        // Add
    case 1:
        result = first + second;
        result.print();
        break;
        // Subtract
    case 2:
        result = first - second;
        result.print();
        break;
        // Multiply
    case 3:
        result = first * second;
        result.print();
        break;

    case 4: // Copy constructor
    {
        Polynomial third(first);
        if (third.degCoeff == first.degCoeff)
        {
            cout << "false" << endl;
        }
        else
        {
            cout << "true" << endl;
        }
        break;
    }

    case 5: // Copy assignment operator
    {
        Polynomial fourth(first);
        if (fourth.degCoeff == first.degCoeff)
        {
            cout << "false" << endl;
        }
        else
        {
            cout << "true" << endl;
        }
        break;
    }
    }

    return 0;
}