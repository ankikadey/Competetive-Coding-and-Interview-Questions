#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int countConsistentCars(const string& allowedComponents, const vector<string>& models) {
    unordered_set<char> allowedSet(allowedComponents.begin(), allowedComponents.end());
    int consistentCount = 0;

    for (const string& model : models) {
        bool consistent = true;
        for (char component : model) {
            if (allowedSet.find(component) == allowedSet.end()) {
                consistent = false;
                break;
            }
        }
        if (consistent) {
            consistentCount++;
        }
    }

    return consistentCount;
}

int main() {
    string allowedComponents;
    cin >> allowedComponents;

    int n;
    cin >> n;

    vector<string> models(n);
    for (int i = 0; i < n; ++i) {
        cin >> models[i];
    }

    int result = countConsistentCars(allowedComponents, models);
    cout << result << endl;

    return 0;
}