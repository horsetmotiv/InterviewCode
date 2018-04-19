#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// 自己的第一种解法 成功ac

// 官方题解的网址  和我的解法思想差不多
// https://www.nowcoder.com/questionTerminal/215881ffac304a52812eff45aea8330d

int test() {
    int n;
    while (cin >> n) {
        int sum = 0;
        for (int i = 2; i < n; i++) {
            int temp = n;
            while (temp) {
                sum += temp % i;
                temp /= i;
            }
        }
        int commonMax = gcd(sum, n - 2);
        cout << sum / commonMax << "/" << (n - 2) / commonMax << endl;
    }
    return 0;
}