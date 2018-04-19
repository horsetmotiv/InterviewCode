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
// https://www.nowcoder.com/questionTerminal/7eb53c86e50845f6a2eafe7ea0fe9ef9
int test() {
    string s;
    cin >> s;
    if (s.find('.') == string::npos) {
        cout << "null" << endl;
    } else {
        cout << s.substr(s.find('.') + 1) << endl;
    }
    return 0;
}