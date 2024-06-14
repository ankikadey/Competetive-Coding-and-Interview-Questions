#include <vector>
#include <utility>
using namespace std;

class Solution {
 public:
  int largestAltitude(vector<int>& gain) {
    int ans = 0;
    int currAltitude = 0;
    for (const int g : gain) {
      currAltitude += g;
      ans = max(ans, currAltitude);
    }
    return ans;
  }
};