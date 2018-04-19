#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
bool isPrime(int n) {
    int m = sqrt(n);
    for (int i = 2; i <= m; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// 自己的第一种解法 一次ac

// 官方题解的答案 写的没我的解法好
// https://www.nowcoder.com/questionTerminal/c96d6acc025541ffb79c579688f8d003
int test() {
    int n;
    cin >> n;
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }
    int m = primes.size(), res = 0;
    for (int i = 0, j = m - 1; i <= j;) {
        if (primes[i] + primes[j] < n) {
            i++;
        } else if (primes[i] + primes[j] > n) {
            j--;
        } else {
            res++;
            i++, j--;
        }
    }
    cout << res << endl;
    return 0;
}