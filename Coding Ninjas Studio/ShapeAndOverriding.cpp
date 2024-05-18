#include <iostream>
using namespace std;

class Shape
{
protected:
    string shapeType;

public:
    Shape(string type) : shapeType(type) {}

    void printMyType()
    {
        cout << shapeType << endl;
    }
};

class Square : public Shape
{
private:
    int length;

public:
    Square(int len) : Shape("square"), length(len) {}

    int calculateArea()
    {
        return length * length;
    }

    void printMyType()
    {
        Shape::printMyType();
    }
};

class Rectangle : public Shape
{
private:
    int length;
    int breadth;

public:
    Rectangle(int len, int br) : Shape("rectangle"), length(len), breadth(br) {}

    int calculateArea()
    {
        return length * breadth;
    }

    void printMyType()
    {
        Shape::printMyType();
    }
};

int main()
{
    Square square(5);
    square.printMyType();
    cout << square.calculateArea() << endl;

    Rectangle rectangle(5, 4);
    rectangle.printMyType();
    cout << rectangle.calculateArea() << endl;

    return 0;
}
