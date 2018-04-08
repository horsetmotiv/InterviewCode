// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 这题确实写不出来 下次准备用自己的思路做出来
// https://blog.csdn.net/zjucor/article/details/65438454
// https://www.nowcoder.com/discuss/6967?type=1&order=0&pos=5&page=0
int calc(vector<vector<int>> &sum, int x, int y, int i, int j) {
    return sum[x][y] - sum[x][j] - sum[i][y] + sum[i][j];
}
bool judge(vector<vector<int>> &sum, int x, int m, int n) {
    for (int i = 1; i <= m - 3; i++) {
        for (int j = i + 1; j <= m - 2; j++) {
            for (int k = j + 1; k <= m - 1; k++) {
                int last = 0, cnt = 0;
                for (int r = 1; r <= n; r++) {
                    int s1 = calc(sum, r, i, last, 0);
                    int s2 = calc(sum, r, j, last, i);
                    int s3 = calc(sum, r, k, last, j);
                    int s4 = calc(sum, r, m, last, k);
                    if (s1 >= x && s2 >= x && s3 >= x && s4 >= x) {
                        last = r;
                        cnt++;
                    }
                }
                if (cnt >= 4)
                    return true;
            }
        }
    }
    return false;
}
int test() {
    int m, n;
    cin >> n >> m;
    vector<vector<int>> matrix(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++) {
            matrix[i][j] = s[j - 1] - '0';
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] +
                        matrix[i][j];
        }
    }

    //二分查找的算法
    int left = 0, right = sum[n][m];
    int res = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (judge(sum, mid, m, n)) {
            left = mid + 1;
            res = mid;
        } else {
            right = mid - 1;
        }
    }
    cout << res << endl;
    return 0;
}
// int binary_search()