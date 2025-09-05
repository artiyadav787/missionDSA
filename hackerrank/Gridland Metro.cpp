#include <bits/stdc++.h>
using namespace std;

long gridlandMetro(int n, int m, int k, vector<vector<int>> tracks) {
    unordered_map<int, vector<pair<int,int>>> rowTracks;

    // Step 1: group by row
    for (auto &t : tracks) {
        int r = t[0], c1 = t[1], c2 = t[2];
        rowTracks[r].push_back({c1, c2});
    }

    long occupied = 0;

    // Step 2: process each row
    for (auto &entry : rowTracks) {
        auto &intervals = entry.second;
        sort(intervals.begin(), intervals.end());

        int curStart = intervals[0].first;
        int curEnd   = intervals[0].second;

        for (int i = 1; i < intervals.size(); i++) {
            int s = intervals[i].first;
            int e = intervals[i].second;

            if (s <= curEnd + 1) {
                // merge overlap
                curEnd = max(curEnd, e);
            } else {
                // finalize previous interval
                occupied += (long)(curEnd - curStart + 1);
                curStart = s;
                curEnd   = e;
            }
        }
        // add last merged interval
        occupied += (long)(curEnd - curStart + 1);
    }

    long totalCells = (long)n * m;
    return totalCells - occupied;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> tracks(k, vector<int>(3));
    for (int i = 0; i < k; i++) {
        cin >> tracks[i][0] >> tracks[i][1] >> tracks[i][2];
    }

    cout << gridlandMetro(n, m, k, tracks) << "\n";
    return 0;
}
