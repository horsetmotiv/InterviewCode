// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;


// 这题还是挺简单的 下面是自己的第一种解法
int test() {
    int n, sum = 0;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % n != 0) {
        cout << -1 << endl;
        return 0;
    }
    int averNum = sum / n;
    int diff = 0;
    for (int i = 0; i < n; i++) {
        if ((a[i] - averNum) % 2 != 0) {
            cout << -1 << endl;
            return 0;
        }
        if (a[i] - averNum < 0) {
            diff += averNum - a[i];
        }
    }
    cout << diff / 2 << endl;
    return 0;
}