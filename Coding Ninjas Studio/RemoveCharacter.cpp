#include <iostream>
#include <string>

using namespace std;

string removeCharacter(const string& str, char X) {
    string result;
    for (char c : str) {
        if (c != X) {
            result += c;
        }
    }
    return result;
}

int main() {
    string inputString;
    char characterToRemove;

    getline(cin, inputString);

    cin >> characterToRemove;

    string result = removeCharacter(inputString, characterToRemove);

    if (result == inputString) {
        cout << inputString << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
