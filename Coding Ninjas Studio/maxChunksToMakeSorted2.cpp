/* You are given an integer array arr.

We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.

Return the largest number of chunks we can make to sort the array.

 

Example 1:

Input: arr = [5,4,3,2,1]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 2, 3], which isn't sorted.
Example 2:

Input: arr = [2,1,3,4,4]
Output: 4
Explanation:
We can split into two chunks, such as [2, 1], [3, 4, 4].
However, splitting into [2, 1], [3], [4], [4] is the highest number of chunks possible.
 
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maxChunksToSorted(vector<int>& arr) {
    stack<int> st;  // Create a stack to track the ranges of each chunk
    for (int num : arr) {
        if (!st.empty() && num < st.top()) {
            // If the current number is smaller than the top of the stack,
            // we've reached the end of a chunk.
            
            int top = st.top();  // Store the top element of the stack
            while (!st.empty() && num < st.top()) {
                // Pop elements from the stack until the condition is no longer met
                st.pop();
            }
            st.push(top);  // Push the stored top element back onto the stack
        } else {
            st.push(num);  // Push the current number onto the stack
        }
    }
    return st.size();  // The size of the stack gives the maximum number of chunks
}

int main() {
    vector<int> arr1 = {5, 4, 3, 2, 1};
    vector<int> arr2 = {2, 1, 3, 4, 4};
    
    cout << maxChunksToSorted(arr1) << endl;  // Output: 1
    cout << maxChunksToSorted(arr2) << endl;  // Output: 4
    
    return 0;
}
