#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

bool isSubsequence(string &s, string &t) {
    int i = 0, j = 0;
    for (; i < s.size() && j < t.size(); j++) {
        if (s[i] == t[j]) {
            i++;
        }
    }
    return i == s.size();
}

// 比较简单的题目 自己的第一种解法 一次ac
// 官方题解的答案 写的没我的方案好
// https://www.nowcoder.com/questionTerminal/ac18db43a404459da9c72e8aa1816f80
int test() {
    string s, first, second;
    while (cin >> s >> first >> second) {
        string fs = first + second;
        bool isForword = false, isBackward = false;
        if (isSubsequence(fs, s)) {
            isForword = true;
        }
        reverse(s.begin(), s.end());
        if (isSubsequence(fs, s)) {
            isBackward = true;
        }

        if (isForword && isBackward) {
            cout << "both" << endl;
        } else if (isForword) {
            cout << "forward" << endl;
        } else if (isBackward) {
            cout << "backward" << endl;
        } else {
            cout << "invalid" << endl;
        }
    }
    return 0;
}