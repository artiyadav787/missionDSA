#include <bits/stdc++.h>
using namespace std;

long sumXor(long n) {
    if (n == 0) return 1; // special case: n = 0

    int zeroBits = 0;
    while (n > 0) {
        if ((n & 1) == 0) zeroBits++; // count zero bits
        n >>= 1;
    }
    return 1L << zeroBits; // 2^zeroBits
}

int main() {
    long n;
    cin >> n;
    cout << sumXor(n) << endl;
    return 0;
}
