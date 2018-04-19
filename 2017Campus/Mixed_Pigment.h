#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 这题并不会 直接看的下面的答案 思想是高斯消元法
// https://blog.csdn.net/huzhigenlaohu/article/details/52264154
// https://www.nowcoder.com/questionTerminal/5b1116081ee549f882970eca84b4785a
int test() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    set<int> dir;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        int num = nums[i];
        for (auto it = dir.rbegin(); it != dir.rend(); it++) {
            if ((num ^ *it) < num) {
                num = num ^ *it;
            }
        }
        if (num) {
            dir.insert(num);
        }
    }
    cout << dir.size() << endl;
    return 0;
}