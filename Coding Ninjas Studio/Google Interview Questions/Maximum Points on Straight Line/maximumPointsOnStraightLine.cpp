#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

pair<int, int> getSlope(int x1, int y1, int x2, int y2) {
    if (x1 == x2) {
        return {numeric_limits<int>::max(), numeric_limits<int>::max()}; // Vertical line
    }
    int dx = x2 - x1;
    int dy = y2 - y1;
    int divisor = gcd(dx, dy);
    return {dy / divisor, dx / divisor};
}

// Custom hash function for pair<int, int>
struct pair_hash {
    template <class T1, class T2>
    size_t operator () (const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

int maxPointsOnLine(vector<vector<int>>& points, int n) {
    if (n <= 2) {
        return n; // If there are 0, 1, or 2 points, they can always form a straight line.
    }

    int max_points = 0;
    for (int i = 0; i < n; ++i) {
        unordered_map<pair<int, int>, int, pair_hash> slopes; // Map to store the count of points with the same slope
        int same_point_count = 1; // Initialize with 1 to count the current point itself

        for (int j = 0; j < n; ++j) {
            if (i != j) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                pair<int, int> slope = getSlope(x1, y1, x2, y2);
                slopes[slope]++;
                same_point_count = max(same_point_count, slopes[slope]);
            }
        }

        max_points = max(max_points, same_point_count);
    }

    return max_points+1;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;

        vector<vector<int>> points(N, vector<int>(2));
        for (int i = 0; i < N; ++i) {
            cin >> points[i][0] >> points[i][1];
        }

        cout << maxPointsOnLine(points, N) << endl;
    }

    return 0;
}
