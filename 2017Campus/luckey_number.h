#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 自己的第一种解法 一次ac

// 官方题解的网址
// https://www.nowcoder.com/questionTerminal/4d1afe11171c44a385287e29092cdb3f
int countBinary(int n) {
    int res = 0;
    while (n) {
        res += (n & 1);
        n >>= 1;
    }
    return res;
}
int countDiffSum(int n) {
    int res = 0;
    while (n) {
        res += n % 10;
        n /= 10;
    }
    return res;
}
int test() {
    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (countBinary(i) == countDiffSum(i)) {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}