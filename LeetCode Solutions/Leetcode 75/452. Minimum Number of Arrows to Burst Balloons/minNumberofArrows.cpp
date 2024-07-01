#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

auto speedUp = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int arrows = 1;
        int end = points[0][1];

        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > end) {
                arrows++;
                end = points[i][1]; 
            }
            else {
                end = min(end, points[i][1]);
            }
        }

        return arrows;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        cin >> points[i][0] >> points[i][1];
    }

    Solution solution;
    cout << solution.findMinArrowShots(points) << endl;
    return 0;
}
