#include <bits/stdc++.h>
using namespace std;

long minimumLoss(vector<long> price) {
    int n = price.size();
    vector<pair<long,int>> data;
    data.reserve(n);

    for (int i = 0; i < n; i++) {
        data.push_back({price[i], i});
    }

    sort(data.begin(), data.end()); // sort by price ascending

    long minLoss = LONG_MAX;

    for (int i = 1; i < n; i++) {
        long higherPrice = data[i].first;
        int higherYear = data[i].second;

        long lowerPrice = data[i-1].first;
        int lowerYear = data[i-1].second;

        // Ensure buy happens before sell (higher price must appear earlier in original order)
        if (higherYear < lowerYear) {
            minLoss = min(minLoss, higherPrice - lowerPrice);
        }
    }

    return minLoss;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long> price(n);
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }

    cout << minimumLoss(price) << "\n";
    return 0;
}
