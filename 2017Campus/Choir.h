#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int test() {
    // int student_num;
    // int k, dis;
    // cin >> student_num;
    // vector<int> ability(student_num, 0);
    // for (int i = 0; i < student_num; i++) {
    //     cin >> ability[i];
    // }
    // cin >> k >> dis;
    // vector<vector<int>> dp(student_num + 1, vector<int>(k + 1, 0));
    // dp[0][0] = 1;
    // for (int i = 1; i <= student_num; i++) {
    //     for (int j = 1; j <= i; j++) {
    //         dp[i][j] = max(i - 1 < j ? 0 : dp[i - 1][j],
    //                        dp[i - 1][j - 1] * ability[i - 1]);
    //     }
    // }
    // cout << dp[student_num][k] << endl;
    return 0;
}
// 参考的代码的地址
// https://blog.csdn.net/lezg_bkbj/article/details/52166145
int test1() {
    int student_num;
    int k, dis;
    cin >> student_num;
    vector<int> ability(student_num, 0);
    for (int i = 0; i < student_num; i++) {
        cin >> ability[i];
    }
    cin >> k >> dis;
    vector<vector<long>> dpMax(student_num + 1, vector<long>(k + 1, 0)),
        dpMin(student_num + 1, vector<long>(k + 1, 0));

    long res = LONG_MIN;
    for (int i = 1; i <= student_num; i++) {
        dpMax[i][1] = ability[i - 1];
        dpMin[i][1] = ability[i - 1];
        for (int j = 2; j <= k && j <= i; j++) {
            for (int x = i - 1; x >= max(1, i - dis); x--) {
                long max_num = dpMax[x][j - 1] * ability[i - 1];
                long min_num = dpMin[x][j - 1] * ability[i - 1];
                dpMax[i][j] = max(dpMax[i][j], max(max_num, min_num));
                dpMin[i][j] = min(dpMin[i][j], min(max_num, min_num));
            }
        }
        res = max(res, dpMax[i][k]);
    }
    cout << res << endl;
    // cout << dp[student_num][k] << endl;
    return 0;
}
