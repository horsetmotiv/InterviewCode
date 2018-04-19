#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

/*
input:5 15 5 5 10 2 3
output:4
*/

// 刚开始想迷糊了 其实就是最简单的背包的问题

// 官方题解的网址 题解写的非常的一般 不如自己写的答案好
// https://www.nowcoder.com/questionTerminal/7f24eb7266ce4b0792ce8721d6259800
int test() {
    int n, target;
    cin >> n >> target;
    vector<long> a(n, 0), dp(target + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = target; j >= a[i]; j--) {
            dp[j] += dp[j - a[i]];
        }
    }
    cout << dp[target] << endl;
    return 0;
}