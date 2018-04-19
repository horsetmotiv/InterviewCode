#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
// 自己的第一种解法 成功ac 花了不少时间在调试  核心思想是约瑟夫环

// 牛客网的官方的题解在下面的链接中 题解中最好的解法还是用了反向的思维
// 就是不容易想到
// https://www.nowcoder.com/questionTerminal/657d09e2b3704574814089ba8566d98d
int test() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n, 0);
        int counter = 0;
        int num = 0;
        for (int j = 0, i = 1; i <= n; j = (j + 1) % n) {
            if (a[j] == 0) {
                counter++;
                if (counter == 2 || i == n) {
                    a[j] = i++;
                    num++;
                    counter = 0;
                }
            }
        }
        int m = a.size();
        for (int i = 0; i < m - 1; i++) {
            cout << a[i] << " ";
        }
        cout << a[m - 1] << endl;
    }
    return 0;
}

// 官方题解里面的答案

int test2 {
    int t, n;
    cin >> t;
    while (t--) {
        deque<int> q;
        cin >> n;
        for (int i = n; i > 0; i--) {
            q.push_front(i);
            int temp = q.back();
            q.pop_back();
            q.push_front(temp);
        }
        for (int i = 0; i < q.size(); i++)
            cout << q[i] << " ";
        cout << endl;
    }
    return 0;
}