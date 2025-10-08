#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> losses;
        for (auto &m : matches) {
            int w = m[0], l = m[1];
            if (losses.find(w) == losses.end()) losses[w] = 0;
            losses[l]++; // if loser not present it will be created and incremented
        }

        vector<int> noLoss, oneLoss;
        for (auto &p : losses) {
            if (p.second == 0) noLoss.push_back(p.first);
            else if (p.second == 1) oneLoss.push_back(p.first);
        }

        sort(noLoss.begin(), noLoss.end());
        sort(oneLoss.begin(), oneLoss.end());
        return {noLoss, oneLoss};
    }
};
