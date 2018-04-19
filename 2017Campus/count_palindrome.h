#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
bool isPalindrome(string &s) {
    int m = s.size();
    for (int i = 0, j = m - 1; i < j; i++, j--) {
        if (s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

// 网易的这题也是非常的简单 第一次就ac了
int test() {
    string a, b;
    cin >> a >> b;
    int m = a.size(), res = 0;
    for (int i = 0; i <= m; i++) {
        string temp = a.substr(0, i) + b + a.substr(i);
        res += isPalindrome(temp) ? 1 : 0;
    }
    cout << res << endl;
    return 0;
}

// python的解法更加的简单 答案来自与官方的答案
// https://www.nowcoder.com/questionTerminal/9d1559511b3849deaa71b576fa7009dc