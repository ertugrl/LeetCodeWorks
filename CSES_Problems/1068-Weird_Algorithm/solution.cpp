// CSES Problem 1068: Weird Algorithm
// Link: https://cses.fi/problemset/task/1068/
// Description: Consider an algorithm that takes as input a positive integer n. If n is even, th...

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>

using namespace std;

int main() {
    long long n;
    cin >> n;

    while (n != 1) {
        cout << n << " ";
        n = (n % 2 == 0 ? n / 2 : n * 3 + 1);
    }

    cout << 1;

    return 0;
}
