#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int MissingNumber(vector<int> &array, int N)
    {
        // Step 1: Calculate the expected sum of the first N natural numbers
        int totalSum = N * (N + 1) / 2;

        // Step 2: Calculate the sum of the elements in the array
        int arraySum = 0;
        for (int num : array)
        {
            arraySum += num;
        }

        // Step 3: The missing number is the difference between the total sum and the array sum
        return totalSum - arraySum;
    }
};

int main()
{
    Solution solution;

    vector<int> array1 = {1, 2, 3, 5};
    int N1 = 5;
    cout << solution.MissingNumber(array1, N1) << endl; // Output: 4

    vector<int> array2 = {6, 1, 2, 8, 3, 4, 7, 10, 5};
    int N2 = 10;
    cout << solution.MissingNumber(array2, N2) << endl; // Output: 9

    return 0;
}
