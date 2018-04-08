// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 自己的第一种写法 这题还是非常的简单的 就是一个数学的问题 直接求根就行
int test() {
    long h;
    cin >> h;
    cout << (int)(-1 + sqrt(1 + 4 * h)) / 2 << endl;
    return 0;
}