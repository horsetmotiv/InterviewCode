#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 自己的第一种方案  一次ac

// 官方题解的网址  题解写的都没我的答案好
// https://www.nowcoder.com/questionTerminal/e3f67da21c3f45bfb091cf0cabb9bb0f
int test() {
    unordered_map<char, int> dir;
    string s;
    getline(cin, s);
    for (int i = 0, m = s.size(); i < m; i++) {
        if (isalpha(s[i]) && ++dir[s[i]] == 3) {
            cout << s[i] << endl;
            break;
        }
    }
    return 0;
}