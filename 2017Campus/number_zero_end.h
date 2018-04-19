#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
// 和LeetCode172题一模一样
// https://leetcode.com/problems/factorial-trailing-zeroes/discuss/52373/simple-cc-solution-with-detailed-explaination

// 官方题解的网址
// https://www.nowcoder.com/questionTerminal/6ffdd7e4197c403e88c6a8aa3e7a332a


int test() {
    int n;
    cin >> n;
    int ans = 0;
    while (n >= 5) { //用除避免溢出
        n /= 5;
        ans += n;
    }
    cout << ans << endl;
    return 0;
}