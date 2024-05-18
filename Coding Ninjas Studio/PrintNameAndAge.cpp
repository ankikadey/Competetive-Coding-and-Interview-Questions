#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    void SetValue(const string &name, int age)
    {
        this->name = name;
        this->age = age;
    }

    void GetValue() const
    {
        cout << "The name of the person is " << name << " and the age is " << age << ".";
    }
};

int main()
{
    Person person;

    string name;
    int age;

    getline(cin, name); // Read the name (including spaces)
    cin >> age;         // Read the age

    person.SetValue(name, age);
    person.GetValue();

    return 0;
}
