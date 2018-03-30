#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
输入例子1:
2
3
.X.
11
...XX....XX
输出例子1:
1
3
*/
int test() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '.') {
                res++;
                s[i] = 'X';
                if (i + 1 >= s.size()) {
                    continue;
                }
                s[i + 1] = 'X';
                if (i + 2 >= s.size()) {
                    continue;
                }
                s[i + 2] = 'X';
            }
        }
        cout << res << endl;
    }
    return 0;
}