#include <bits/stdc++.h>
using namespace std;

string highestValuePalindrome(string s, int n, int k) {
    vector<bool> changed(n, false);
    int l = 0, r = n - 1;

    // Pass 1: make it a palindrome
    while (l < r) {
        if (s[l] != s[r]) {
            if (k <= 0) return "-1";
            if (s[l] > s[r]) s[r] = s[l];
            else s[l] = s[r];
            changed[l] = changed[r] = true;
            k--;
        }
        l++; r--;
    }

    // Pass 2: maximize value
    l = 0; r = n - 1;
    while (l <= r && k > 0) {
        if (l == r) {
            // middle element in odd length
            if (s[l] != '9' && k > 0) {
                s[l] = '9';
                k--;
            }
        } else {
            if (s[l] != '9') {
                if (changed[l] || changed[r]) {
                    // already changed once -> only 1 change needed
                    if (k >= 1) {
                        s[l] = s[r] = '9';
                        k--;
                    }
                } else {
                    // not changed before -> need 2 changes
                    if (k >= 2) {
                        s[l] = s[r] = '9';
                        k -= 2;
                    }
                }
            }
        }
        l++; r--;
    }

    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;

    cout << highestValuePalindrome(s, n, k) << "\n";
    return 0;
}
