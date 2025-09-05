#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
  
    size_t n;
    cin >> n;
    
    vector<size_t> numbers;
    for (size_t i = 0; i < n; ++i){
        size_t number;
        cin >> number;
        
        // keep numbers sorted
        numbers.insert(lower_bound(numbers.begin(), numbers.end(), number), number);
        
        double median;
        if (i % 2 == 0){ // odd number of elements
            median = numbers[i / 2];
        }
        else{ // even
            median = (double(numbers[i / 2]) + numbers[i / 2 + 1]) / 2;
        }
        cout << fixed << setprecision(1) << median << "\n";
    }
    return 0;
}
