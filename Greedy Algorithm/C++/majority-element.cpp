#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(const vector<int> &A) {
        int count = 0;
        int candidate;

        for (int num : A) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 2, 3};
    int result = solution.majorityElement(nums);
    cout << "Majority Element: " << result << endl;
    return 0;
}
