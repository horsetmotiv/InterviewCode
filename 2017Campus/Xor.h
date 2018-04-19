#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
// 这题没写出来
// 自己暴力的解法 只通过了80%的测试用例

// 官方题解的网址 这题暂时以后有时间再看
// https://www.nowcoder.com/questionTerminal/fc05f68c5f47438db54c6923ef23cf4a

int test() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long res = 0;
    // sort(a.begin(), a.end(), greater<int>());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((a[i] ^ a[j]) > m) {
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}