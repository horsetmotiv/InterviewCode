#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 这题是挺简单的 但是题目的说明太智障了

// 官方题解的答案
// https://www.nowcoder.com/questionTerminal/5a0a2c7e431e4fbbbb1ff32ac6e8dfa0

int test() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(2 * n, 0), b(2 * n, 0);
        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
        }
        for (int p = 0; p < k; p++) {
            int start = 0;
            for (int i = n - 1, j = 2 * n - 1; i >= 0 && j >= n; i--, j--) {
                b[start++] = a[j];
                b[start++] = a[i];
            }
            reverse(b.begin(), b.end());
            swap(a, b);
        }
        for (int i = 0; i < 2 * n - 1; i++) {
            cout << a[i] << " ";
        }
        cout << a[2 * n - 1] << endl;
    }
    return 0;
}

// 官方题解的答案
// https://www.nowcoder.com/questionTerminal/5a0a2c7e431e4fbbbb1ff32ac6e8dfa0
int test2() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(2 * n, 0), b(2 * n, 0);
        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
        }
        for (int p = 0; p < k; p++) {
            b = a;
            for (int i = 0; i < n; i++) {
                a[2 * i] = b[i];
                a[2 * i + 1] = b[i + n];
            }
        }
        for (int i = 0; i < 2 * n - 1; i++) {
            cout << a[i] << " ";
        }
        cout << a[2 * n - 1] << endl;
    }
    return 0;
}