#include <bits/stdc++.h>
using namespace std;

long long jokes(const vector<pair<int,int>>& events) {
    unordered_map<long long, long long> freq;
    freq.reserve(events.size()*2);
    for (auto [m, d] : events) {
        if (m < 2) continue; // unary invalid
        string s = to_string(d);
        bool ok = true;
        for (char c : s) {
            if (c - '0' >= m) { ok = false; break; }
        }
        if (!ok) continue;
        long long v = 0;
        for (char c : s) v = v * m + (c - '0');
        ++freq[v];
    }
    long long ans = 0;
    for (auto& kv : freq) {
        long long c = kv.second;
        ans += c * (c - 1) / 2;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    if (!(cin >> n)) return 0;
    vector<pair<int,int>> events(n);
    for (int i = 0; i < n; ++i) cin >> events[i].first >> events[i].second;
    cout << jokes(events) << "\n";
    return 0;
}
