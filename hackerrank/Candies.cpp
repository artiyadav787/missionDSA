#include <bits/stdc++.h>
using namespace std;

long candies(int n, vector<int> arr) {
    vector<int> candy(n, 1); // Step 1: Every child gets at least 1 candy
    
    // Step 2: Left to Right
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            candy[i] = candy[i - 1] + 1;
        }
    }
    
    // Step 3: Right to Left
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > arr[i + 1]) {
            candy[i] = max(candy[i], candy[i + 1] + 1);
        }
    }
    
    // Step 4: Sum up candies
    long total = 0;
    for (int c : candy) {
        total += c;
    }
    return total;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << candies(n, arr) << endl;
    return 0;
}
