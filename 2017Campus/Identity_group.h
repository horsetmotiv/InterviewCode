#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 自己的第一种解法 一次ac、

// 官方题解的网址
// https://www.nowcoder.com/questionTerminal/58766632a6cc45c0a1158fea2db91728
int test() {
    string s;
    vector<string> strs;
    while (getline(cin, s)) {
        while (s.find(' ') != string::npos) {
            s.erase(' ');
        }
        strs.push_back(s);
    }
    // sort(strs.begin(), strs.end());
    for (int i = 0, m = strs.size(); i < m; i++) {
        for (int j = 0; j < strs[i].size(); j++) {
            cout << strs[i][j];
            if (j == 5 || j == 13) {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}