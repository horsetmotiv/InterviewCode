#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
// 自己的第一种解法就成功ac了 其实这道题还是挺简单的

// 官方题解的网址 题解写的还没我自己的方案牛逼
// https://www.nowcoder.com/questionTerminal/0147cbd790724bc9ae0b779aaf7c5b50
int test() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int i = 0, j = n - 1;
    int counter = 0;
    while (i < j) {
        if (a[i] < a[j]) {
            a[i + 1] += a[i];
            i++;
            counter++;
        } else if (a[i] > a[j]) {
            a[j - 1] += a[j];
            j--;
            counter++;
        } else {
            i++, j--;
        }
    }
    cout << counter << endl;
    return 0;
}