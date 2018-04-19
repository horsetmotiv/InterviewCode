#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
//这破题也是一次就ac了
//官方论坛的题解也是在下面 写的一般 没有我的解法牛逼
// https://www.nowcoder.com/questionTerminal/cd763d8541fc4243b8d3b967bb6d6b6a
int test() {
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> points[i].second;
    }
    sort(points.begin(), points.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) {
             return a.first + a.second < b.first + b.second;
         });
    cout << points[0].first - 1 + points[0].second - 1 << endl;
    return 0;
}