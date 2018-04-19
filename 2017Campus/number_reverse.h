#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 这题比较简单 一次ac

// 官方题解的答案的网址
// https://www.nowcoder.com/questionTerminal/bc62febdd1034a73a62224affe8bddf2
int test() {
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int num = stoi(a) + stoi(b);
    auto result = to_string(num);
    reverse(result.begin(), result.end());
    auto res = stoi(result);
    cout << res << endl;
    return 0;
}

int rev(int num) {
    int x = 0;
    while (num != 0) {
        x = 10 * x + num % 10;
        num = num / 10;
    }
    return x;
}

// 官方的题解的方法  比我的方法好
int test2() {
    int a, b;
    cin >> a >> b;
    cout << rev(rev(a) + rev(b)) << endl;
    return 0;
}