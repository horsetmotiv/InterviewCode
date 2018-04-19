#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
// 自己的第一种解法 成功ac 花了一点时间在调试上

// 下面是题解的网址
// https://www.nowcoder.com/questionTerminal/0960cb46233b446687b77facc9148b89
int test() {
    int distance;
    cin >> distance;
    if (distance == 0) {
        cout << 1 << endl;
        return 0;
    }
    int limit = sqrt(distance);
    int i = 0, j = limit;
    int res = 0;
    while (i <= j) {
        long temp = i * i + j * j;
        if (temp == distance) {
            if (i == 0 || j == 0 || i == j) {
                res += 4;
            } else {
                res += 8;
            }
            i++, j--;
        } else if (temp < distance) {
            i++;
        } else {
            j--;
        }
    }
    cout << res << endl;
    return 0;
}

//这里是官方题解的解法
int test2() {
    int distance;
    cin >> distance;
    int res = 0;
    int limit = sqrt(distance);
    for (int i = 1; i <= limit; i++) {
        int x = sqrt(distance - i * i);
        if (x * x + i * i == distance) {
            res += 4;
        }
    }
    cout << res << endl;
    return 0;
}