#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count0 = 0, count1 = 0;

        // count preferences
        for (int s : students) {
            if (s == 0) count0++;
            else count1++;
        }

        // simulate sandwiches
        for (int s : sandwiches) {
            if (s == 0) {
                if (count0 == 0) return count1; // no one wants 0
                count0--;
            } else {
                if (count1 == 0) return count0; // no one wants 1
                count1--;
            }
        }

        return 0; // all students ate
    }
};
