#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 这题直接看得官方的题解 确实没想到 不过这种题目自己应该能想出来

// 官方题解的网址
// https://www.nowcoder.com/questionTerminal/7e7ccd30004347e89490fefeb2190ad2
int test() {
    int n;
    while (cin >> n) {
        long long pre = 3, cur = 9;
        for (int i = 3; i <= n; i++) {
            long long temp = cur;
            cur = 2 * cur + pre;
            pre = temp;
        }
        cout << cur << endl;
    }
    return 0;
}