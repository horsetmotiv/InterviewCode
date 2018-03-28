#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

// 第一种方案 只通过了70%的测试用例
class Solution {
  public:
    int test() {
        int left, right;
        cin >> left >> right;
        int res = 0, counter = 0;
        string s;
        for (int i = 1; i < left; i++) {
            res += resolveNum(i);
            if (res % 3 == 0) {
                res = 0;
            }
        }
        for (int i = left; i <= right; i++) {
            res += resolveNum(i);
            if (res % 3 == 0) {
                res = 0;
                counter++;
            }
        }
        cout << counter << endl;
        return 0;
    }
    int resolveNum(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            res += s[i] - '0';
        }
        return res;
    }
    int resolveNum(int num) {
        int res = 0;
        while (num) {
            res += num % 10;
            num /= 10;
        }
        return res;
    }
};

// 解答 直接看的网上的答案 原来这题是有规律的
// https://www.nowcoder.com/questionTerminal/51dcb4eef6004f6f8f44d927463ad5e8
/*
找出规律:
sum: 1 3 6 ... (n^2 + n) / 2
*/
// https://www.nowcoder.com/questionTerminal/51dcb4eef6004f6f8f44d927463ad5e8
class Solution_1 {
  public:
    int test() {
        auto comp = [](int x) { return (x + 2) / 3; };
        int left, right;
        cin >> left >> right;
        cout << right - left + 1 - comp(right) + comp(left - 1);
        return 0;
    }
};