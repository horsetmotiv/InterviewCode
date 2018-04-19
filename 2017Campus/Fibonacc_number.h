#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
// 牛客网官方的题解的网址
// https://www.nowcoder.com/questionTerminal/18ecd0ecf5ef4fe9ba3f17f8d00d2d66

// 题目比较简单 自己的第一种解法
int test() {
    int N;
    cin >> N;
    vector<int> dp;
    dp.push_back(0);
    dp.push_back(1);
    for (int i = 2; dp[i - 1] <= N; i++) {
        int temp = dp[i - 1] + dp[i - 2];
        dp.push_back(temp);
    }
    auto it1 = lower_bound(dp.begin(), dp.end(), N);
    auto it2 = upper_bound(dp.begin(), dp.end(), N);
    it2--;
    cout << min(abs(N - *it1), abs(N - *it2)) << endl;
    return 0;
}

// 上面的简化版
int test2() {
    int N;
    cin >> N;
    int a = 0, b = 1;
    while (b < N) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    cout << min(b - N, N - a);
    return 0;
}