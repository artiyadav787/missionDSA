#include <bits/stdc++.h>
using namespace std;

int toys(vector<int> w) {
    sort(w.begin(), w.end());
    int containers = 0;
    int i = 0, n = w.size();

    while (i < n) {
        containers++;
        int minWeight = w[i];  
        // Fill current container
        while (i < n && w[i] <= minWeight + 4) {
            i++;
        }
    }
    return containers;
}

int main() {
    int n;
    cin >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];

    cout << toys(w) << endl;
    return 0;
}

