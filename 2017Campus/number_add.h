#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 自己的第一种解法 一次ac 题目比较简单

// 官方题解的网址 官方的题解比我的答案差远了
// https://www.nowcoder.com/questionTerminal/850fde3d987f4b678171abd88cf05710
bool islegal(string &a) {
    for (int i = 0, m = a.size(); i < m; i++) {
        if (!isdigit(a[i])) {
            return false;
        }
    }
    return true;
}
int test() {
    string a, b;
    cin >> a >> b;
    string res;
    if (islegal(a) && islegal(b)) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int sum = 0, i = 0, j = 0, m = a.size(), n = b.size();
        while (i < m || j < n || sum) {
            sum += (i < m ? a[i++] - '0' : 0) + (j < m ? b[j++] - '0' : 0);
            res += (sum % 10 + '0');
            sum /= 10;
        }
        reverse(res.begin(), res.end());
        cout << res << endl;
    } else {
        cout << "Error" << endl;
    }
    return 0;
}