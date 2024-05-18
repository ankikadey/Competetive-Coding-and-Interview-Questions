#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits>
#include <utility>

using namespace std;

long long distance(const pair<int, int>& p1, const pair<int, int>& p2) {
    long long x_diff = static_cast<long long>(p1.first) - p2.first;
    long long y_diff = static_cast<long long>(p1.second) - p2.second;
    return x_diff * x_diff + y_diff * y_diff;
}

long long closestPairUtil(pair<int, int>* coordinates, int low, int high) {
    if (high - low <= 3) {
        long long minDist = numeric_limits<long long>::max();
        for (int i = low; i < high; ++i) {
            for (int j = i + 1; j < high; ++j) {
                minDist = min(minDist, distance(coordinates[i], coordinates[j]));
            }
        }
        return minDist;
    }

    int mid = (low + high) / 2;
    long long leftMinDist = closestPairUtil(coordinates, low, mid);
    long long rightMinDist = closestPairUtil(coordinates, mid, high);
    long long minDist = min(leftMinDist, rightMinDist);

    vector<pair<int, int>> strip;
    for (int i = low; i < high; ++i) {
        long long dx = coordinates[i].first - coordinates[mid].first;
        if (dx * dx < minDist) {
            strip.push_back(coordinates[i]);
        }
    }

    sort(strip.begin(), strip.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second;
    });

    int stripSize = strip.size();
    for (int i = 0; i < stripSize; ++i) {
        for (int j = i + 1; j < stripSize && (strip[j].second - strip[i].second) * (strip[j].second - strip[i].second) < minDist; ++j) {
            minDist = min(minDist, distance(strip[i], strip[j]));
        }
    }

    return minDist;
}

long closestPair(pair<int, int>* coordinates, int n) {
    sort(coordinates, coordinates + n);
    return closestPairUtil(coordinates, 0, n);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    
    return 0;
}
