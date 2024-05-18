#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int countWords(const string& str) {
    istringstream iss(str);
    int count = 0;
    string word;
    
    while (iss >> word) {
        count++;
    }
    
    return count;
}

int main() {
    string inputString;
    getline(cin, inputString);

    int wordCount = countWords(inputString);
    cout << wordCount << endl;

    return 0;
}
