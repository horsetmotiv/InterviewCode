#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 自己的第一种解法 简单的完全背包的问题  调试了一下后 成功ac

// 官方题解的网址  官方题解最好的答案和我的方法一模一样
// https://www.nowcoder.com/questionTerminal/14cf13771cd840849a402b848b5c1c93
int test() {
    vector<int> money = {1, 5, 10, 20, 50, 100};
    int n;
    cin >> n;
    vector<long> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < money.size(); i++) {
        for (int j = 1; j <= n; j++) {
            dp[j] += (j < money[i] ? 0 : dp[j - money[i]]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}