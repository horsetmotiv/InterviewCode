#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
// 自己的第一种解法 成功ac

// 下面是牛客网的官方的题解的网址
// https://www.nowcoder.com/questionTerminal/876e3c5fcfa5469f8376370d5de87c06

vector<int> visited(2000000, 0);
void helper(vector<int> &a, int index, int sum) {
    for (int i = index; i < a.size(); i++) {
        if (i == index || a[i] != a[i - 1]) {
            visited[a[i] + sum] = 1;
            helper(a, i + 1, sum + a[i]);
        }
    }
}
int test() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    helper(a, 0, 0);
    for (int i = 1; i < 2000000; i++) {
        if (visited[i] == 0) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}

// 下面的解法来自牛客网
int test2() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int miss = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > miss + 1) {
            break;
            // cout << miss + 1 << endl;
            // return 0;
        }
        miss += a[i];
    }
    cout << miss + 1 << endl;
    return 0;
}