// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 直接暴力的解法 感觉不是很好 虽然ac了
// 答案参考自下面的链接
// https://www.nowcoder.com/questionTerminal/b698e67a2f5b450a824527e82ed7495d
// https://blog.csdn.net/a342500329a/article/details/63744916
// https://blog.csdn.net/a342500329a/article/details/63744916
int counter(vector<int> &arry) {
    int cont = 0;
    for (unsigned int i = 0; i < arry.size() - 1; i++) {
        for (unsigned int j = i + 1; j < arry.size(); j++) {
            if (arry[i] < arry[j])
                cont++;
        }
    }
    return cont;
}

int test() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n, 0);
    set<int> dir;
    for (int i = 1; i <= n; i++) {
        dir.insert(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != 0) {
            dir.erase(a[i]);
        }
    }
    int res = 0;
    vector<int> subs(dir.begin(), dir.end());
    do {
        auto temp = a;
        for (int i = 0, j = 0; i < a.size(); i++) {
            if (temp[i] == 0) {
                temp[i] = subs[j++];
            }
        }
        if (counter(temp) == k) {
            res++;
        }
    } while (next_permutation(subs.begin(), subs.end()));
    cout << res << endl;
    return 0;
}