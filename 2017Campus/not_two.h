#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
// 数学问题 没想出来
// https://www.cnblogs.com/ranranblog/p/5780466.html
// https://blog.csdn.net/waltonhuang/article/details/52149734
// https://www.nowcoder.com/questionTerminal/1183548cd48446b38da501e58d5944eb
int test() {
    int w, h;
    int res = 0;
    cin >> w >> h;
    if (w % 4 == 0 || h % 4 == 0) {
        res = w * h / 2;
    } else if (w % 2 == 0 && h % 2 == 0) {
        res = (w * h / 4 + 1) * 2;
    } else {
        res = w * h / 2 + 1;
    }
    cout << res << endl;
    return 0;
}

int test1() {
    int w, h;
    int res = 0;
    cin >> w >> h;
    vector<vector<int>> matrix(w, vector<int>(h, 0));
    for (int i = 0; i < w; i++) {
        if (i % 4 == 0 || i % 4 == 1) {
            for (int j = 0; j < h; j++) {
                if (j % 4 == 0 || j % 4 == 1) {
                    matrix[i][j] = 1;
                    res++;
                }
            }
        } else {
            for (int j = 0; j < h; j++) {
                if (j % 4 == 2 || j % 4 == 3) {
                    matrix[i][j] = 1;
                    res++;
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}