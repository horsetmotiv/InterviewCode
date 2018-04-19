#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 第一次就ac了 但是花了一点时间

// 官方题解的网址
// https://www.nowcoder.com/questionTerminal/7f26bfeccfa44a17b6b269621304dd4a

int test() {
    string s;
    int num;
    cin >> s >> num;
    int counter = 0;
    int index = 0;
    int m = s.size();
    string res;
    int remain = m - num;
    while (counter < remain && index < m) {
        int maxIndex = index;
        for (int i = index + 1; i <= m - (remain - counter); i++) {
            if (s[i] > s[maxIndex]) {
                maxIndex = i;
            }
        }
        res.push_back(s[maxIndex]);
        counter++;
        index = maxIndex + 1;
    }
    cout << res << endl;
    return 0;
}

// 上面的稍微的修改版
int test2() {
    string s;
    int num;
    cin >> s >> num;
    int counter = 0, index = 0, m = s.size();
    string res;
    int remain = m - num;
    for (int i = 0; i < remain; i++) {
        int maxIndex = index;
        for (int j = index + 1; j <= m - (remain - i); j++) {
            if (s[j] > s[maxIndex]) {
                maxIndex = j;
            }
        }
        res.push_back(s[maxIndex]);
        index = maxIndex + 1;
    }
    cout << res << endl;
    return 0;
}