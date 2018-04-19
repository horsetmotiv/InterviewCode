#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 自己的第一种解法 一次ac 题目比较简单 就是普通的最大的连续的数组和的问题

// 官方题解的网址
// https://www.nowcoder.com/questionTerminal/5a304c109a544aef9b583dce23f5f5db
int test() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sum = 0, res = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (sum < 0) {
            sum = a[i];
        } else {
            sum += a[i];
        }
        res = max(res, sum);
    }
    cout << res << endl;
    return 0;
}