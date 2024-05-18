/* Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.

Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.

 

Example 1:

Input: n = 12
Output: 21
Example 2:

Input: n = 21
Output: -1
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        string numStr = to_string(n);
        
        int i = numStr.size() - 2;
        while (i >= 0 && numStr[i] >= numStr[i + 1]) {
            i--;
        }
        
        if (i == -1) {
            return -1; // No next greater element possible
        }
        
        int j = numStr.size() - 1;
        while (j > i && numStr[j] <= numStr[i]) {
            j--;
        }
        
        swap(numStr[i], numStr[j]);
        
        reverse(numStr.begin() + i + 1, numStr.end());
        
        long long nextNum = stoll(numStr);
        
        if (nextNum <= INT32_MAX) {
            return static_cast<int>(nextNum);
        } else {
            return -1;
        }
    }
};

int main() {
    Solution solution;
    
    int n1 = 12;
    cout << solution.nextGreaterElement(n1) << endl; // Output: 21

    int n2 = 21;
    cout << solution.nextGreaterElement(n2) << endl; // Output: -1
    
    return 0;
}
