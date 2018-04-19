#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 自己的第一种方案 超时 通过了70%的用例

// 官方题解的网址
// https://www.nowcoder.com/questionTerminal/4284c8f466814870bae7799a07d49ec8

int test() {
    int n, m;
    cin >> n >> m;
    vector<int> dp(m + 1, -1);
    dp[n] = 0;
    for (int i = n; i <= m; i++) {
        if (dp[i] != -1) {
            for (int j = 2; j <= i / 2 && (i + j <= m); j++) {
                if (i % j == 0) {
                    dp[i + j] = dp[i + j] == -1 ? (dp[i] + 1)
                                                : min(dp[i + j], dp[i] + 1);
                }
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}
// 下面是我改进后的版本 就不超时了
// 官方题解下面有一个答案和我的这个答案基本上一模一样 不过
// 我还是觉得自己的写的更好
int test2() {
    int n, m;
    cin >> n >> m;
    vector<int> dp(m + 1, -1);
    dp[n] = 0;
    for (int i = n; i <= m; i++) {
        if (dp[i] != -1) {
            int limit = sqrt(i);
            for (int j = 2; j <= limit; j++) {
                if (i % j == 0) {
                    if (i + j <= m) {
                        dp[i + j] = dp[i + j] == -1 ? (dp[i] + 1)
                                                    : min(dp[i + j], dp[i] + 1);
                    }
                    int another = i / j;
                    if (i + another <= m) {
                        dp[i + another] = dp[i + another] == -1
                                              ? (dp[i] + 1)
                                              : min(dp[i + another], dp[i] + 1);
                    }
                }
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}