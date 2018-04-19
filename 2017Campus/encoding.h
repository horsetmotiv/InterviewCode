#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 腾讯的第一题 感觉束手无策 没写出来  这题自己还会再看一遍 再写一遍
// 官方题解的网址
// https://www.nowcoder.com/questionTerminal/6fc8716ee33e4cc59d58d7e18712094e
// https://blog.csdn.net/jiangnanyouzi/article/details/6827534

// 下面是题解的答案
int test() {
    vector<int> factor = {1 + 25 + 25 * 25 + 25 * 25 * 25, 1 + 25 + 25 * 25,
                          1 + 25, 1};
    string s;
    cin >> s;
    int index = 0;
    for (int i = 0, m = s.size(); i < m; i++) {
        index += factor[i] * (s[i] - 'a');
    }
    cout << (index + s.size() - 1) << endl;
    return 0;
}