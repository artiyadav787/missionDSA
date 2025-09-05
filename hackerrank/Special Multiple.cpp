#include <bits/stdc++.h>
using namespace std;

string findSpecialMultiple(int N) {
    if (N == 0) return "0"; // not required per constraints (N>=1), but safe
    vector<int> parent(N, -2);   // parent remainder (-2 means unvisited)
    vector<char> via(N, 0);     // digit used to come to this remainder
    queue<int> q;

    int r = 9 % N;
    parent[r] = -1;   // start marker
    via[r] = '9';
    q.push(r);

    if (r == 0) return "9";

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        // try append '0'
        int r0 = (cur * 10) % N; // adding '0'
        if (parent[r0] == -2) {
            parent[r0] = cur;
            via[r0] = '0';
            if (r0 == 0) break;
            q.push(r0);
        }

        // try append '9'
        int r9 = (cur * 10 + 9) % N; // adding '9'
        if (parent[r9] == -2) {
            parent[r9] = cur;
            via[r9] = '9';
            if (r9 == 0) break;
            q.push(r9);
        }
    }

    // reconstruct answer from remainder 0
    string ans;
    int cur = 0; // remainder 0
    while (cur != -1) {
        ans.push_back(via[cur]);
        cur = parent[cur];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N; cin >> N;
        cout << findSpecialMultiple(N) << '\n';
    }
    return 0;
}
