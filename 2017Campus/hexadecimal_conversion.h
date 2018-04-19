#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 自己的第一次的解法 成功ac

// 这里是官方题解的网址
// https://www.nowcoder.com/questionTerminal/ac61207721a34b74b06597fe6eb67c52

int test() {
    int m, n;
    cin >> m >> n;
    vector<char> res;
    int sig = m >= 0 ? 1 : -1;
    m = abs(m);
    while (m) {
        int temp = m % n;
        res.push_back(temp >= 10 ? temp - 10 + 'A' : temp + '0');
        m /= n;
    }
    reverse(res.begin(), res.end());
    if (sig == -1) {
        cout << '-';
    }
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
    }
    cout << endl;
    return 0;
}