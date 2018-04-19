#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 自己的第一种方案 想不到过了全部的测试用例 真是智障
// 这道题不该是这样子写的才对
int test() {
    int m, n;
    cin >> m >> n;
    if (m < 1 || m > 1024 || n < 1 || n > 1024) {
        cout << -1 << endl;
        return 0;
    }
    if (m == n) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}

// 这才是正确的解题思路 来自牛客网的正确的题解

int test2() {
    int m, n;
    vector<unsigned int> bits(32, 0);
    while (cin >> m >> n) {
        if (m < 1 || m > 1024 || n < 1 || n > 1024) {
            cout << -1 << endl;
            continue;
        }
        int index = (m - 1) / 32, bit = (m - 1) % 32;
        bits[index] |= (1 << bit);

        index = (n - 1) / 32, bit = (n - 1) % 32;
        if (bits[index] & (1 << bit)) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}