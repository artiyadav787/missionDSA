#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0; // pointer for popped

        for (int x : pushed) {
            st.push(x); // simulate push
            // keep popping if top matches popped[j]
            while (!st.empty() && j < popped.size() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }

        return st.empty();
    }
};
