#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 简单题 一次ac

// 官方题解的网址 题解写的一般般 没我的好
// https://www.nowcoder.com/questionTerminal/1b58fbb97bc048b8a4438173c5392167
int test() {
    vector<int> a(10001, 0);
    int index = 0;
    for (int i = 0; i < 9997; i++) {
        cin >> index;
        a[index] = 1;
    }
    string s;
    for (int i = 1; i <= 10000; i++) {
        if (a[i] == 0) {
            s += to_string(i);
        }
    }
    long num = stol(s);
    cout << num % 7 << endl;
    return 0;
}