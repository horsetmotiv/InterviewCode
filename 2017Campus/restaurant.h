#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
// 自己的第一种解法  成功ac 官方的题解写的还没我好

// 官方题解的网址
// https://www.nowcoder.com/questionTerminal/d2cced737eb54a3aa550f53bb3cc19d0
int test() {
    int n, m;
    cin >> n >> m;
    vector<int> table(n, 0);
    vector<pair<int, int>> guest(m);
    for (int i = 0; i < n; i++) {
        cin >> table[i];
    }
    multiset<int> dir(table.begin(), table.end());
    for (int i = 0; i < m; i++) {
        cin >> guest[i].first >> guest[i].second;
    }
    // sort(table.begin(), table.end(), greater<int>());
    sort(guest.begin(), guest.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) {
             return a.second > b.second;
         });
    int res = 0;
    for (int i = 0; i < m && !dir.empty(); i++) {
        auto it = dir.lower_bound(guest[i].first);
        if (it != dir.end()) {
            dir.erase(it);
            res += guest[i].second;
        }
    }
    cout << res << endl;
    return 0;
}