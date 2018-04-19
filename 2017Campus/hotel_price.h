#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
// 这题没想出来 直接看的答案

// 官方题解的网址 下面是官方的答案 
// https://www.nowcoder.com/questionTerminal/01cb04dc53f54625834f2a86c519dce9
int test() {
    int start, end, price;
    int minStart = INT_MAX, maxEnd = -1;
    vector<int> prices(10000, 0);
    while (cin >> start >> end >> price) {
        for (int i = start; i <= end; i++) {
            prices[i] = price;
        }
        minStart = min(start, minStart);
        maxEnd = max(end, maxEnd);
    }
    cout << "[" << minStart << ", ";
    int i = minStart + 1;
    for (; i <= maxEnd; i++) {
        if (prices[i - 1] != prices[i]) {
            if (prices[i - 1] != 0) {
                cout << i - 1 << ", " << prices[i - 1] << "]";
            }
            if (i < maxEnd && prices[i] != 0) {
                cout << "," << "[" << i << ", ";
            }
        }
    }
    cout << maxEnd << ", " << prices[maxEnd] << "]";
    return 0;
}