#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
/*
4
20 35 23 40
*/

// 自己的第一种解法 调试后成功ac

// 官方题解的答案网址 官方用的dp的写法
// https://www.nowcoder.com/practice/57cf0b1050834901933e9b48daafbb9a?tpId=85&tqId=29875&tPage=3&rp=3&ru=/ta/2017test&qru=/ta/2017test/question-ranking

int test() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (i + 2 < n && a[i] + 20 >= a[i + 2]) {
            i += 2;
        } else if (i + 1 < n && a[i] + 20 >= a[i + 1]) {
            i += 1;
        }
        res++;
    }
    cout << res * 3 - n << endl;
    return 0;
}

// 官方dp的写法
/*
n = int(raw_input())
d = map(int, sys.stdin.readline().split())
d.sort()
dp = [0]*n
dp[0] = 2
for i in range(1,len(d)):
    if dp[i-1] == 0:
        dp[i] = 2
        continue
    if d[i]-d[i-1] >20:
        dp[i] = dp[i-1] + 2
    else:
        dp[i] = dp[i-1] -1
print dp[n-1]
*/