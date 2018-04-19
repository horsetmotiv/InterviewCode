#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 简单题 一次ac 比较麻烦的地方只有要输入带空格的字符串

// 官方题解的网址
// https://www.nowcoder.com/questionTerminal/f0db4c36573d459cae44ac90b90c6212

int test() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    set<char> dir(b.begin(), b.end());
    for (int i = 0, m = a.size(); i < m; i++) {
        if (dir.count(a[i]) == 0) {
            cout << a[i];
        }
    }
    return 0;
}