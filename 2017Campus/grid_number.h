#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 简单题 自己的第一种解法 直接用排列组合来写就好了 成功ac

// 官方题解的网址
// https://www.nowcoder.com/questionTerminal/e27b9fc9c0ec4a17a5064fb6f5ab13e4
int test() {
    int m, n;
    cin >> m >> n;
    m = m + n;
    int m_n_i = 1;
    for (int i = m; i >= m - n + 1; i--) {
        m_n_i *= i;
    }
    int temp = 1;
    for (int i = 1; i <= n; i++) {
        temp *= i;
    }
    cout << m_n_i / temp << endl;
    return 0;
}

// 自己的第二种解法 更加的常规

int test2() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int j = 1; j <= n; j++) {
        dp[0][j] = 1;
    }
    for (int i = 1; i <= m; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    cout << dp[m][n] << endl;
    return 0;
}