#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
/*
5 2
7

*/

// 这题只想到了暴力的解法  通常的解法并没有想出来
int test() {
    int n, k;
    int res = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i % j >= k) {
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}

// 网上的答案
// https://zhuanlan.zhihu.com/p/35032204 这是最好的分析
// https://www.cnblogs.com/cing/p/8668166.html
// https://blog.csdn.net/i000zheng/article/details/79724107
int test1() {
    int n, k;
    long res = 0;
    cin >> n >> k;
    if (k == 0) {
        res = (long)n * (long)n;
        cout << res << endl;
        return 0;
    }
    for (int y = k + 1; y <= n; y++) {
        int factor = n / y;
        res += factor * (y - k);
        res += max(0, n - (factor * y + k) + 1);
    }
    cout << res << endl;
    return 0;
}