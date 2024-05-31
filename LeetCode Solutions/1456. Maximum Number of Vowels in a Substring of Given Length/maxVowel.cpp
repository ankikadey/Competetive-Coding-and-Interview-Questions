#include <string>
using namespace std;

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        int i = 0;
        int j = 0;
        int n = s.length();
        int ans = 0;
        int countOfVowel = 0;
        while (j < n)
        {
            if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
            {
                countOfVowel++;
            }
            if (j - i + 1 == k)
            {
                ans = max(countOfVowel, ans);
                if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                {
                    countOfVowel--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};