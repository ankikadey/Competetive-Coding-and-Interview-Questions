/*Implement Fraction Class with the following properties and functions.
  Properties :
    1.Numerator
    2.Denominator
  Functions :
    1. Parametrized Constructor- Sets the numerator and denominator values.

    2. Add- This function adds the two fraction following the adding up of two fraction rules and 
    updates the first fractional number.
        e.g.
        if f1 = 1/4 and f2 = 3/5
        f1.add(f2); results in: 
            f1 = 17/20 and f2 = 3/5

    3.Multiply- This function multiplies the two fraction and updates the first fractional number.
        e.g.
        if f1 = 1/4 and f2 = 3/5
        f1.multiply(f2); results in: 
            f1 = 3/20 and f2 = 3/5

    4.Simplify- This function simplifies the fractional value. Use inbuilt __gcd() function.
        e.g.
        if f1=5/20, which can be further simplified as 1/4 so this simplify will perform this.

    8. Print() - Prints the final answer in numerator/denominator form.
        e.g.
        if f1 = 1/2 
        f1.print(); prints:
            1/2
    Input Format:
    The first line of input contains two space-separated integer values, 
    which represent numerator and denominator.
  
    The second line of input contains an integer N representing queries to 
    define how many times the operation must occur.
  
    Next, N lines contain 3 space-separated integers representing the type of query, 
    numerator, and denominator.
  
    Output Format:
    Print the value of the fraction after every query in a separate line.

    Input Constraints:
    1 <= numerator <= 100
    1 <=denominator <= 100
    1 <= N <= 15
    type = 1 or 2
*/
#include <iostream>
#include <algorithm>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num, int den) {
        numerator = num;
        denominator = den;
    }

    void add(const Fraction &other) {
        numerator = (numerator * other.denominator) + (other.numerator * denominator);
        denominator *= other.denominator;
        simplify();
    }

    void multiply(const Fraction &other) {
        numerator *= other.numerator;
        denominator *= other.denominator;
        simplify();
    }

    void simplify() {
        int gcd_val = __gcd(numerator, denominator);
        numerator /= gcd_val;
        denominator /= gcd_val;
    }

    void print() const {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {
    int numerator, denominator, N;
    cin >> numerator >> denominator;
    Fraction f1(numerator, denominator);

    cin >> N;

    while (N--) {
        int type, num, den;
        cin >> type >> num >> den;
        Fraction f2(num, den);

        if (type == 1) {
            f1.add(f2);
        } else if (type == 2) {
            f1.multiply(f2);
        } else {
            cout << "Invalid type. Use 1 or 2." << endl;
        }

        f1.print();
    }

    return 0;
}
