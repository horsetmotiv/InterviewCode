#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
// https://www.nowcoder.com/discuss/70736?type=0&order=0&pos=15&page=1
int test1() {
    int n;
    cin >> n;
    vector<int> X1(n, 0), X2(n, 0), Y1(n, 0), Y2(n, 0);
    set<int> xx, yy;
    for (int i = 0; i < n; i++) {
        cin >> X1[i];
        xx.insert(X1[i]);
    }
    for (int i = 0; i < n; i++) {
        cin >> Y1[i];
        yy.insert(Y1[i]);
    }
    for (int i = 0; i < n; i++) {
        cin >> X2[i];
        xx.insert(X2[i]);
    }
    for (int i = 0; i < n; i++) {
        cin >> Y2[i];
        yy.insert(Y2[i]);
    }
    int ans = 0;
    for (int x : xx) {
        for (int y : yy) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (X1[i] <= x && Y1[i] <= y && X2[i] > x && Y2[i] > y)
                    cnt++;
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
    return 0;
}