#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
// 网易的困难题第一次就做出来了
// 题解的网址 感觉题解写的乱七八糟
// https://www.nowcoder.com/questionTerminal/a5190a7c3ec045ce9273beebdfe029ee
int ans = 0;
void helper(vector<int> &v, int sum, int product, int index) {
    for (int i = index; i < v.size(); i++) {
        if (i == index || v[i] != v[i - 1]) {
            if (sum < product && v[i] != 1) {
                return;
            }
            if (sum + v[i] > product * v[i]) {
                ans++;
            }
            helper(v, sum + v[i], product * v[i], i + 1);
        }
    }
}
int test() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    helper(v, 0, 1, 0);
    cout << ans << endl;
    return 0;
}