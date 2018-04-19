#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 这题太简单了 一分钟不到就一次ac了

// 官方题解的网址
// https://www.nowcoder.com/questionTerminal/cc727473d1e248ccb674eb31bd8683dc
int test() {
    int num;
    vector<int> a;
    while (cin >> num) {
        a.push_back(num);
    }
    sort(a.begin(), a.end() - 1);
    cout << a[0];
    for (int i = 1; i < a.back(); i++) {
        cout << " " << a[i];
    }
    return 0;
}