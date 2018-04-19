#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
// 自己的第一种方法 一次ac

// 题解的官方的网址   不过看题解写的比我的解法烂多了
// https://www.nowcoder.com/questionTerminal/bd891093881d4ddf9e56e7cc8416562d
int test() {
    string s;
    cin >> s;
    string res = "";
    for (int i = 0, m = s.size(); i < m; i++) {
        if (isdigit(s[i])) {
            int start = i;
            while (i < m && isdigit(s[i]))
                i++;
            if (i - start > res.size()) {
                res = s.substr(start, i - start);
            }
        }
    }
    cout << res << endl;
    return 0;
}