#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 我的第一种解法 只能求个数 不能输出具体的情况
// int test() {
//     int n, m;
//     cin >> n >> m;
//     vector<int> dp(m + 1, 0);
//     dp[0] = 1;
//     for (int i = 1; i <= n; i++) {
//         for (int j = m; j >= i; j--) {
//             dp[j] += dp[j - i];
//         }
//     }
//     cout << dp[m] << endl;
//     return 0;
// }

// 我的第二种解法 一次ac 递归就能直接写出来 还以为会超时

// 官方题解的网址 官方题解写的一般 没我的方案写的好
// https://www.nowcoder.com/questionTerminal/11cc498832db489786f8a03c3b67d02c
vector<vector<int>> res;
void helper(int start, int n, int current, int target, vector<int> &a) {
    if (current > target) {
        return;
    }
    if (current == target) {
        res.push_back(a);
        return;
    }
    for (int i = start; i <= n; i++) {
        a.push_back(i);
        helper(i + 1, n, current + i, target, a);
        a.pop_back();
    }
}
int test2() {
    int n, m;
    cin >> n >> m;
    vector<int> a;
    helper(1, n, 0, m, a);
    for (int i = 0, m = res.size(); i < m; i++) {
        cout << res[i][0];
        for (int j = 1, n = res[i].size(); j < n; j++) {
            cout << " " << res[i][j];
        }
        cout << endl;
    }
    return 0;
}