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
// https://www.nowcoder.com/questionTerminal/eac8c671a0c345b38aa0c07aba40097b

int test() {
    int n;
    vector<int> a(n, 0);
    while (cin >> n) {
        a.push_back(n);
    }
    int count = 0, current = 0;
    for (int i = 0, m = a.size(); i < m; i++) {
        if (count == 0) {
            current = a[i];
        }
        if (current == a[i]) {
            count++;
        } else {
            count--;
        }
    }
    cout << current << endl;
    return 0;
}