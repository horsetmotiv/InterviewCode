#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 简单题 一次ac

// 官方题解的网址
// https://www.nowcoder.com/questionTerminal/61cfbb2e62104bc8aa3da5d44d38a6ef
int test() {
    int n;
    cin >> n;
    int m = n / 8;
    int res = -1;
    for (int i = m; i >= 0; i--) {
        if ((n - 8 * i) % 6 == 0) {
            res = i + (n - 8 * i) / 6;
            break;
        }
    }
    cout << (res == -1 ? -1 : res) << endl;
    return 0;
}