#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 题目还算简单 但是一开始理解错了精度的含义
// 自己的第一种解法 一次ac
// 官方题解的网址
// https://www.nowcoder.com/questionTerminal/46bd43f043c54013a67816d0a2946506
int test() {
    int n;
    cin >> n;
    int left = -90, right = 90;
    for (int i = 0; i < 6; i++) {
        int mid = (left + right) / 2;
        if (n < mid) {
            right = mid;
            cout << 0;
        } else if (n >= mid) {
            left = mid;
            cout << 1;
        }
    }
    return 0;
}