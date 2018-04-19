#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 简单题 一次ac

// 官方题解的网址
// https://www.nowcoder.com/questionTerminal/02d8d42b197646a5bbd0a98785bb3a34

int test() {
    int a, b, c, d;
    int A, B, C;
    cin >> a >> b >> c >> d;
    A = (a + c) / 2;
    B = A - a;
    C = B - b;
    if (A - B == a || B - C == b || A + B == c || B + C != d) {
        cout << "No" << endl;
    } else {
        cout << A << " " << B << " " << C << endl;
    }
    return 0;
}