#include <unordered_map>
#include <string>
using namespace std;
class Solution
{
public:
    string oddEven(string s)
    {
        unordered_map<char, int> freq;

        // Step 1: Calculate the frequency of each character
        for (char c : s)
        {
            freq[c]++;
        }

        int x = 0;
        int y = 0;

        // Step 2: Determine the positions and update x and y accordingly
        for (const auto &pair : freq)
        {
            char charKey = pair.first;
            int count = pair.second;
            int position = charKey - 'a' + 1; // Get 1-based position in the alphabet

            if (position % 2 == 0)
            { // Even position in alphabet
                if (count % 2 == 0)
                { // Even frequency
                    x++;
                }
            }
            else
            { // Odd position in alphabet
                if (count % 2 == 1)
                { // Odd frequency
                    y++;
                }
            }
        }

        // Step 3: Calculate the sum and determine if it's even or odd
        if ((x + y) % 2 == 0)
        {
            return "EVEN";
        }
        else
        {
            return "ODD";
        }
    }
};