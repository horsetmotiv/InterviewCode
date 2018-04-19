#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
// #include <bits/stdc++.h>
#include <climits>
#include <string>
#include <vector>
using namespace std;

// 这题本质上就是一个动态规划的题目 我感觉还是比较简单的

// 官方的题解的网址
// https://www.nowcoder.com/questionTerminal/74acf832651e45bd9e059c59bc6e1cbf?toCommentId=1118302

// 我的第一种解法  被题目误导了 不是跳到最后一根柱子 而是在这个柱子后面才算通过
// 所以并不是刚好落在最后一根柱子上
int test() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, INT_MAX), nums(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] != INT_MAX && j + nums[j] >= i) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    cout << (dp[n] == INT_MAX ? -1 : dp[n]) << endl;
    return 0;
}

// 官方题解的做法 也是差不多的
int test2() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, INT_MAX), nums(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] != INT_MAX && j + nums[j] >= i) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    cout << (dp[n] == INT_MAX ? -1 : dp[n]) << endl;
    return 0;
}