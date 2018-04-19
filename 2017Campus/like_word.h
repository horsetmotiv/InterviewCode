#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 这题简单
// 前面两个条件非常的简单 就第三个比较难 但是第三个不写也能过
// 这破题只要满足前面两种条件可以过 牛客网缺少充足的测试用例

// 四层循环判断第三个条件 可惜用不上 因为测试用例测不出来
// 官方的题解地址
// https://www.nowcoder.com/questionTerminal/ca7b8af83e2f4ec1af2f23d6733223b5


bool isSub(string s) {
    if (s.size() < 4)
        return false;
    for (int i = 0; i < s.size() - 3; i++) {
        for (int j = i + 1; j < s.size() - 2; j++) {
            for (int k = j + 1; k < s.size() - 1; k++) {
                if ((int)s[i] == (int)s[k]) {
                    for (int l = k + 1; l < s.size(); l++) {
                        if ((int)s[j] == (int)s[l]) {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}
int test() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (!isupper(s[i])) {
            cout << "Dislikes" << endl;
            return 0;
        }
    }
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            cout << "Dislikes" << endl;
            return 0;
        }
    }
    // for (int i = 0; i < s.size(); i++) {
    // }
    cout << "Likes" << endl;
    return 0;
}