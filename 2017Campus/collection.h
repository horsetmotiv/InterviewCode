#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 自己的第一种解法 一次ac

// 官方题解的网址
// https://www.nowcoder.com/questionTerminal/635ff765d4af45b5bf8e3756ed415792
int test() {
    set<int> dir;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m + n; i++) {
        int temp;
        cin >> temp;
        dir.insert(temp);
    }
    auto it = dir.begin();
    cout << *it;
    while (++it != dir.end()) {
        cout << " " << *it;
    }
    return 0;
}