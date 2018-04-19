#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
// 简单题 一次ac

// 官方的题解的网址
// https://www.nowcoder.com/practice/ee5de2e7c45a46a090c1ced2fdc62355?tpId=85&tqId=29867&tPage=2&rp=2&ru=/ta/2017test&qru=/ta/2017test/question-ranking
int test() {
    string s;
    vector<string> res;
    while (cin >> s) {
        res.push_back(s);
    }
    reverse(res.begin(), res.end());
    cout << res[0];
    for (int i = 1, m = res.size(); i < m; i++) {
        cout << " " << res[i];
    }
    return 0;
}