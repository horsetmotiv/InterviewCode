#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 这题没看懂 直接看的答案

// 官方的题解
// https://www.nowcoder.com/questionTerminal/49cb3d0b28954deca7565b8db92c5296
// https://blog.csdn.net/tingting256/article/details/52566915
int test() {
    long num, sum = 0;
    cin >> num;
    for (long i = num; i > 0; i /= 2) {
        long temp = (i + 1) / 2;
        sum += temp * temp;
    }
    cout << sum << endl;
    return 0;
}

long helper(long n) {
    if (n == 1) {
        return 1;
    }
    if (n % 2 == 0) {
        return helper(n / 2) + n * n / 4;
    } else {
        return helper(n - 1) + n;
    }
}
// 官方题解中递归的写法
int test2() {
    long num;
    cin >> num;
    cout << helper(num) << endl;
    return 0;
}