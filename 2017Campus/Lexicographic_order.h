#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 直接看的答案
// 官方题解的网址
// https://www.nowcoder.com/questionTerminal/6c9d8d2e426c4c58bbadfdf67d591696
int test() {
    long n, m;
    cin >> n >> m;
    long i = 1;
    m--;
    while (m != 0) {
        long start = i, end = i + 1;
        long num = 0;
        while (start <= n) {
            num += min(n + 1, end) - start;
            start *= 10;
            end *= 10;
        }
        if (num > m) {
            i *= 10;
            m--;
        } else {
            m -= num;
            i++;
        }
    }
    cout << i << endl;
    return 0;
}